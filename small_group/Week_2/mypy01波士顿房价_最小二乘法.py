import numpy as np
import pandas as pd
import matplotlib.pyplot as plt


class multiLinerRegression:
    def __init__(self, filename):
        self.weight = None  # 权重
        self.load_file(filename)
        self.train(self.train_x, self.train_y)  # 训练
        self.predict(self.predict_x)  # 测试集
        self.mistake(self.real_y, self.predict_result)

    def load_file(self, filename):
        # 从文件中导入数据
        boston = pd.read_csv(filename)
        boston = boston.dropna()  # 删除有空元素的行

        # 归一化处理
        boston = np.array(boston)

        # 数据预处理, 数据归一化,原始数据经过数据归一化/标准化处理后，各指标处于同一数量级
        maxinum = boston.max(axis=0)  # axis=0代表竖轴,从左往右求每一列最大最小
        mininum = boston.min(axis=0)

        # 归一化处理开始,归一化公式
        for i in range(13):
            boston[:, i] = (boston[:, i] - mininum[i]) / (maxinum[i] - mininum[i])

        # 划分训练集和测试机,比例为80% 20%
        offset = int(boston.shape[0] * 0.8)
        train_data = boston[:offset]
        predict_data = boston[offset:]

        # 区分训练集和测试集
        self.train_x = train_data[:, :-1]  # 将特征和标签分开
        self.train_y = train_data[:, -1:]
        self.predict_x = predict_data[:, :-1]
        self.real_y = predict_data[:, -1:]

    def train(self, train_x, train_y):
        assert (train_x.shape[0] == train_y.shape[0])  # 确保有几个样本,就有多少个y
        one = np.ones((train_x.shape[0], 1))  # 全部是1,作为欧米噶0,也就是b偏移量
        character = np.hstack((one, train_x))  # 合并,形成特征值的数组,也就是变量
        self.weight = np.linalg.inv(character.T.dot(character)).dot(character.T).dot(train_y)  # 根据权重公式,w= (X^T *
        # X)^{-1} * X^T * y
        print("计算的权重向量为:\n", self.weight)
        print('----------------------------------\n\n')
        return self

    def predict(self, predict_x):
        one = np.ones((predict_x.shape[0], 1))
        character = np.hstack((one, predict_x))
        self.predict_result = character.dot(self.weight)
        print("预测结果为:\n", self.predict_result)
        print('----------------------------------\n\n')

    def mistake(self, real_y, predict_y):
        loss = 0
        lenght = len(real_y)
        for i in range(lenght):
            loss += (real_y[i] - predict_y[i]) ** 2  # 最小二乘法计算误差
        loss = loss / len(real_y)
        print("损失函数的值为:", loss)

        x = [i for i in range(self.predict_x.shape[0])]
        plt.scatter(x, self.predict_result)  # 其中一个颜色是预测值,另一个颜色是真实值
        plt.scatter(x, self.real_y)
        plt.savefig("最小二乘法预测图像", dpi=999)
        plt.show()


a = multiLinerRegression(r"boston_housing_data.csv")
