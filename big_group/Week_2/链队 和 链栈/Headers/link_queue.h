#define  _CRT_SECURE_NO_WARNINGS 1
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int Status;
typedef int ElemType;


typedef struct QueueNode {//定义链队的每个节点
	void* data;
	int flag;//这是一个标记,1代表data是整形,2代表字符,3代表字符串
	struct Queue* next;
}QueueNode;


typedef struct {//定义链队
	QueueNode* front;
	QueueNode* rere;
}LQueue;

Status initLQueue(LQueue* Q);//初始化队列
Status isEmptyQueue(LQueue* Q);//判断队列是否为空
Status EntryQueue(LQueue* Q);//入队
Status OutQueue(LQueue* Q);//出队
Status GetFrontQueue(LQueue* Q);//获取队列第一个元素
Status LenghtQueue(LQueue* Q);//获取队列长度
QueueNode* DestoryQueue(LQueue* Q);//销毁队列
Status ClearQueue(LQueue* Q);//清空队列
Status TraverseLQueue(LQueue*);//遍历队列
void LPrint(QueueNode* p);//定义一个打印函数,根据data类型不同,选择不同的打印方式