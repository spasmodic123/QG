#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <string.h>

void creat_200000_data()//先随机创建20万的随机数据,存到文件中
{
	FILE* fp;
	fp = fopen("200000_data", "w");
	srand((unsigned)time(NULL));
	for (int i = 0; i < 200000; i++) {
		fprintf(fp, "%d ", rand());
	}
	fclose(fp);
}


void save_data(char* filename, int* arr, int lenght)
{
	FILE* fp;//将排序后的数据存入新的文件中
	fp = fopen(filename, "w");
	for (int i = 0; i < lenght; i++) {
		fprintf(fp, "%d ", arr[i]);
	}
	fclose(fp);
	printf("排序后的文件已经放入新的文件中!\n文件名为 %s", filename);
	system("pause");
}


void insert_sort(int*a,int lenght,char *filename)//从小到大排序
{
	for (int i = 1; i < lenght; i++) {
		if (a[i] < a[i - 1]) {//比较当前位置,如果该元素小于前面的一个,就一直往前面遍历
			int j = i;
			while (j > 0) {//如果大于前面的,一直交换,直到大于或等于前一个元素
				if (a[j] >= a[j - 1])break;
				else if (a[j] < a[j - 1]) {
					int tmp;
					tmp = a[j - 1];
					a[j - 1] = a[j];
					a[j] = tmp;
					j--;
				}
			}
		}
	}
}




void Merge(int sourceArr[], int tempArr[], int startIndex, int midIndex, int endIndex) {
	int i = startIndex, j = midIndex + 1, k = startIndex;//i是拆分出来第一个数组的头指针,k是新的有序数组tmp的头指针,j是拆分出来第二个数组的头指针
	//三个指针巧妙运用,将该轮拆分出来的两个数组里面的数字,按照从小到大顺序排列到新的有序数组tmp中去

	while (i != midIndex + 1 && j != endIndex + 1) {
		if (sourceArr[i] > sourceArr[j])//tmp为有序数组,根据拆分出来的多个sourcearr数组中的每一个数字进行判断,按照从小到大放到新的tmp数组中去
			tempArr[k++] = sourceArr[j++];
		else
			tempArr[k++] = sourceArr[i++];
	}
	while (i != midIndex + 1)
		tempArr[k++] = sourceArr[i++];
	while (j != endIndex + 1)
		tempArr[k++] = sourceArr[j++];
	for (i = startIndex; i <= endIndex; i++)//最后,改变最开始的数组
		sourceArr[i] = tempArr[i];
}



//内部使用递归
void MergeSort(int sourceArr[], int tempArr[], int startIndex, int endIndex) {
	int midIndex;
	if (startIndex < endIndex) {
		midIndex = startIndex + (endIndex - startIndex) / 2;
		//双递归,比较抽象     举例说明⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇
		//对应上面merge函数
		//9876543210右边部分拆分成 43  2  10  第一次合并,指针从头到尾,也就是下标8和9,排序后tmp数组后半部分变成了01,source数组(起始数组)后半部分变为43  2  01
		//                                    第二次合并,指针从头到尾,也就是下标7到9,排序后tmp数组后半部分变成了012,source数组(起始数组)后半部分变为43  0  12
		//                                    第三次合并,指针从头到尾,也就是下标5到9,排序后tmp数组后半部分变成了01234,source数组(起始数组)后半部分变为01  2  34
		MergeSort(sourceArr, tempArr, startIndex, midIndex);//拆分,注意理解,这一条语句和下一条语句是同时执行的,而不是先后.从中间分为两大段进行拆分     
		//!!!!!!很重要一点,上一条语句的中间指针midindex,拆分之后,变成了新的,拆分后的数组的尾指针
		//!!!!!!同理,下面的中间指针midindex+1,拆分之后,就是新的,拆分后的数组的头指针
		MergeSort(sourceArr, tempArr, midIndex + 1, endIndex);//拆分

		Merge(sourceArr, tempArr, startIndex, midIndex, endIndex);//合并
	}
}



int jungle_data_quantity()
{
	while (1) {
		printf("请选择你想要使用的数据\t1.一万 / 2.五万 / 3.二十万 / 4.返回上一级  / 5.大量小数据量(100个数据*100k次)\n");//选择测试哪一个量级的数据
		int choice; char c;
		printf("请输入你的选择:");//判断非法输入
		int ret = scanf("%d", &choice);//scanf函数的返回值为成功读取的元素的个数,如果是%d,你却输入了一个字母,那么成功读取数目为0
		if (ret < 1) {
			while ((c = getchar()) != EOF && c != '\n');//利用getchar函数,不断读取,清除缓存区域
			printf("输入非法!!!请重新输入   \033[31m应该输入一个整数 \033[0m\n");
			system("pause");
		}
		else {
			return choice;
		}
	}
}



void Quick_Sort(int* arr, int begin, int end) {
	if (begin > end)
		return;
	int tmp = arr[begin];//设置基准数,一般为数组第一个
	int i = begin;
	int j = end;
	while (i != j) {
		while (arr[j] >= tmp && j > i)//最右边的先移动,直到找到一个小于基准数的数
			j--;
		while (arr[i] <= tmp && j > i)//左边的开始移动,直到找到一个大于基准数的数
			i++;
		if (j > i) {//两指针都已经找到符合要求的数,交换两个数的位置
			int t = arr[i];
			arr[i] = arr[j];
			arr[j] = t;
		}
	}//两指针相遇,循环结束,此时该位置左边的数都是小于或者等于基准数,右边的都是大于或者等于基准数,然后把基准数放在这个该位置就可以了
	arr[begin] = arr[i];
	arr[i] = tmp;
	Quick_Sort(arr, begin, i - 1);//拆出来的部分继续按照上面的步骤不断排序
	Quick_Sort(arr, i + 1, end);//此语句与上面的语句同时进行
}



void count_sort(int* arr, int lenght,char*filename)
{
	static count[32768];//因为rand()随机生成的最大值为32767
	static int sort[200000];//有序的新数组
	for (int i = 0; i <= 32767; i++) {
		count[i] = 0;//先把全部元素设为0
	}
	for (int i = 0; i < lenght; i++) {
		count[arr[i]]++;//计数板,遇到对应的元素,对应元素的个数就加一
	}
	for (int i = 1; i <= 32767; i++) {
		count[i] += count[i - 1];//每一个元素的个数,等于自己加上前面,比自己大的元素 的个数 的和,   此操作为了方便后续后续新数组的位置分配
	}

	//先解释为什么第三个for循环要把自己的个数加上前面的所有数的个数:  因为,比如元素1 2 3,个数都为5个,                                                //则元素3应该放在第11个--第15个位置,对应下标就是10--14,这就是第一个(减减--)符号的意义!
	//如果arr[j-1]是元素3,则 count[arr[j - 1]] 就是元素3的个数和排前面的数 的个数 总和,再减一,就是对应
    //的下标位置,也就是14   
	//如果下一次继续遇到元素3,那么下标的位置就变为了13      一直重复此步骤,直到元素3对应的下标位置10--14被填满
	//其他所有的元素按照上文逻辑,类推

	for (int j = lenght; j > 0; j--) {
		sort[--count[arr[j - 1]]] = arr[j - 1];
	}

	for (int o = 0; o < 100; o++) {
		//printf("%d ", sort[o]);
	}
	save_data(filename, sort, lenght);//将数据保存到新的文件中
}


int maxbit(int data[], int n) //辅助函数，求数据的最大位数,到底是个位十位还是百位千位
{
	int maxData = data[0];      ///< 最大数
	for (int i = 1; i < n; ++i)
	{
		if (maxData < data[i])
			maxData = data[i];
	}
	int d = 1;
	int p = 10;
	while (maxData >= p)
	{
		maxData /= 10;
		++d;
	}
	return d;//返回最大的位数,最大的数有几位,后面就要排列多少次
}

void radio_sort(int* data, int lenght,char*filename)
{
	clock_t start = clock();

	int max = maxbit(data, lenght);//先求出最大的位数,决定了要排序多少轮
	static int tmp[200000];//储存经过排列一次后,新的数据
	int count[10];//计数器,计算在当前的这一位 (个位/百位/或者千位) 所拥有的元素的个数   ,比如11,12,13,21,25,31 这一串数据,在各位排序中,就是1有三个,
	//2有一个,3有一个,5有一个       如果是十位数,则1有3个,2有两个,3有一个

	int i, j, k;
	int radix = 1;
	for (i = 1; i <= max; i++) //进行max次排序, 对应  个十百千万
	{
		for (j = 0; j < 10; j++)
			count[j] = 0; //每次分配前清空计数器
		for (j = 0; j < lenght; j++)
		{
			k = (data[j] / radix) % 10; //统计每个桶中的记录数
			count[k]++;
		}
		for (j = 1; j < 10; j++)
			count[j] = count[j - 1] + count[j]; //将tmp中的位置依次分配给每个桶,此处的思维模式与上文计数排序类似
		//每一个元素的个数,等于自己加上前面,比自己 现在的位数 大的元素 的个数 的和,   此操作为了方便后续后续新数组的位置分配
		for (j = lenght - 1; j >= 0; j--) //将所有桶中记录依次收集到tmp中,排列一次后的新的顺序,放入tmp数组
		{
			k = (data[j] / radix) % 10;
			tmp[count[k] - 1] = data[j];//减减是因为坐标从零开始,需要减一
			count[k]--;
		}
		for (j = 0; j < lenght; j++) //将临时数组的内容复制到data中
			data[j] = tmp[j];
		radix = radix * 10;//从低位到高位排序
	}

	clock_t run_time = clock() - start;

	printf("运算时间为 %dms\n\n", run_time);
	save_data(filename, data, lenght);//将数据保存到新的文件中
}


void function_name(int num)
{
	if (num == 1) {
		system("cls");
		printf("\t\t\t\t\t\t\033[33m插入排序功能 \033[0m\n\n");
		printf("  ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
	}
	else if (num == 2) {
		system("cls");
		printf("\t\t\t\t\t\t\033[33m归并排序功能 \033[0m\n\n");
		printf("  ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
	}
	else if (num == 3) {
		system("cls");
		printf("\t\t\t\t\t\t\033[33m快速排序功能 \033[0m\n\n");
		printf("  ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
	}
	else if (num == 4) {
		system("cls");
		printf("\t\t\t\t\t\t\033[33m计数排序功能 \033[0m\n\n");
		printf("  ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
	}
	else if (num == 5) {
		system("cls");
		printf("\t\t\t\t\t\t\033[33m基数排序功能 \033[0m\n\n");
		printf("  ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
	}
}





int sl[50];
int sr[50];
int sp = 0;
//入栈
int PUSH(int A, int B)
{
	sl[sp] = A;
	sr[sp] = B;
	sp++;
}
//出栈
int POP(int* pl, int* pr)
{
	sp--;
	*pl = sl[sp];
	*pr = sr[sp];
}
//迭代法快速排序
void quicksort_interation(int* a, int l, int r)
{
	int i, j, p, t;

	PUSH(l, r);

	while (sp) {	//栈空即跳出循环
		POP(&l, &r);
		i = l;
		j = r;
		p = a[(i + j) / 2];	//设定基准值（随意设定，不一定是中间的数）
		while (i <= j) {
			while (a[i] < p)
				i++;
			while (a[j] > p)
				j--;
			if (i <= j) {	//交换数
				t = a[i];
				a[i] = a[j];
				a[j] = t;
				i++;
				j--;
			}
		}
		//判断是否结束（当l=j时，只有一个元素，不需要排序；
		//当l>j时，没有元素。不需要压栈）
		if (l < j)
			PUSH(l, j);
		if (i < r)
			PUSH(i, r);
	}
}




//冒泡排序优化1
void BubbleSort_super1(int* arr, int size)//添加标记法
{
	int i = 0, j = 0;

	for (i = 0; i < size - 1; i++)//一共要排序size-1次
	{
		//每次遍历标志位都要先置为0，才能判断后面的元素是否发生了交换
		int flag = 0;

		for (j = 0; j < size - 1 - i; j++)//选出该趟排序的最大值往后移动
		{
			if (arr[j] > arr[j + 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				flag = 1;//只要有发生了交换，flag就置为1
			}
		}

		//判断标志位是否为0，如果为0，说明整体的元素已经有序，就直接return
		if (flag == 0)
		{
			return;
		}
	}
}




void BubbleSort_super2(int* arr, int size)
{
	int i = 0, j = 0;
	int k = size - 1, pos = 0;//pos变量用来标记循环里最后一次交换的位置,设置k=size-1是因为每一次大循环后,如果发现后半部分局部有序,则下一轮循环,
	//对于后半部分有序的就不用继续循环了

	for (i = 0; i < size - 1; i++)//一共要排序size-1次
	{
		//每次遍历标志位都要先置为0，才能判断后面的元素是否发生了交换
		int flag = 0;

		for (j = 0; j < k; j++)//选出该趟排序的最大值往后移动,k就是pos位置,pos位置后面的已经有序
		{
			if (arr[j] > arr[j + 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				flag = 1;//只要有发生了交换，flag就置为1
				pos = j;//循环里最后一次交换的位置 j赋给pos
			}
		}

		k = pos;
		//判断标志位是否为0，如果为0，说明后面的元素已经有序，就直接return
		if (flag == 0)
		{
			return;
		}
	}
}




void BubbleSort_super3(int arr[], int size)//相比于第二种优化,区别在于,第二种优化知道了后面有一部分是有序的,所以副循环不用遍历完,遍历到pos就可以停止
{                                   //而第三种优化,相当于前面一部分也可以局部有序,因为循环一次后,最小值会被放到前面
	                                //所以开始的时候也无需从头开始循环,继续节省时间
	int i = 0;
	int j = 0;
	int n = 0;//同时找最大值的最小需要两个下标遍历
	int flag = 0;
	int pos = 0;//用来记录最后一次交换的位置
	int k = size - 1;
	for (i = 0; i < size - 1; i++)//确定排序趟数
	{
		pos = 0;
		flag = 0;
		//正向寻找最大值
		for (j = n; j < k; j++)//确定比较次数
		{
			if (arr[j] > arr[j + 1])
			{
				//交换
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				flag = 1;//加入标记
				pos = j;//交换元素，记录最后一次交换的位置
			}
		}
		if (flag == 0)//如果没有交换过元素，则已经有序,直接结束
		{
			return;
		}
		k = pos;//下一次比较到记录位置即可
		//反向寻找最小值
		for (j = k; j > n; j--)
		{
			if(arr[j]<arr[j-1]){
				int tmp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = tmp;
				flag = 1;
			}
		}
		n++;//最小的经过一轮循环放到的下标0,第二小的数就是下标1,类推
		if (flag == 0)//如果没有交换过元素，则已经有序,直接结束
		{
			return;
		}
	}
}


































//与上面一样,只是是否保存数据进行了微调///////////////////////////////////////////////////////////////////////////////////////////////////////////////
void radio_sort_lots(int* data, int lenght, char* filename)//与上面一样,只是是否保存数据进行了微调
{

	int max = maxbit(data, lenght);//先求出最大的位数,决定了要排序多少轮
	static int tmp[200000];//储存经过排列一次后,新的数据
	int count[10];//计数器,计算在当前的这一位 (个位/百位/或者千位) 所拥有的元素的个数   ,比如11,12,13,21,25,31 这一串数据,在各位排序中,就是1有三个,
	//2有一个,3有一个,5有一个       如果是十位数,则1有3个,2有两个,3有一个

	int i, j, k;
	int radix = 1;
	for (i = 1; i <= max; i++) //进行max次排序, 对应  个十百千万
	{
		for (j = 0; j < 10; j++)
			count[j] = 0; //每次分配前清空计数器
		for (j = 0; j < lenght; j++)
		{
			k = (data[j] / radix) % 10; //统计每个桶中的记录数
			count[k]++;
		}
		for (j = 1; j < 10; j++)
			count[j] = count[j - 1] + count[j]; //将tmp中的位置依次分配给每个桶,此处的思维模式与上文计数排序类似
		//每一个元素的个数,等于自己加上前面,比自己 现在的位数 大的元素 的个数 的和,   此操作为了方便后续后续新数组的位置分配
		for (j = lenght - 1; j >= 0; j--) //将所有桶中记录依次收集到tmp中,排列一次后的新的顺序,放入tmp数组
		{
			k = (data[j] / radix) % 10;
			tmp[count[k] - 1] = data[j];//减减是因为坐标从零开始,需要减一
			count[k]--;
		}
		for (j = 0; j < lenght; j++) //将临时数组的内容复制到data中
			data[j] = tmp[j];
		radix = radix * 10;//从低位到高位排序
	}
}




void count_sort_lots(int* arr, int lenght, char* filename)//无保存,与上面的函数功能一样,只是否保存数据进行了微调
{
	static count[32768];//因为rand()随机生成的最大值为32767
	static int sort[200000];//有序的新数组
	for (int i = 0; i <= 32767; i++) {
		count[i] = 0;//先把全部元素设为0
	}
	for (int i = 0; i < lenght; i++) {
		count[arr[i]]++;//计数板,遇到对应的元素,对应元素的个数就加一
	}
	for (int i = 1; i <= 32767; i++) {
		count[i] += count[i - 1];//每一个元素的个数,等于自己加上前面,比自己大的元素 的个数 的和,   此操作为了方便后续后续新数组的位置分配
	}

	//先解释为什么第三个for循环要把自己的个数加上前面的所有数的个数:  因为,比如元素1 2 3,个数都为5个,                                                //则元素3应该放在第11个--第15个位置,对应下标就是10--14,这就是第一个(减减--)符号的意义!
	//如果arr[j-1]是元素3,则 count[arr[j - 1]] 就是元素3的个数和排前面的数 的个数 总和,再减一,就是对应
	//的下标位置,也就是14   
	//如果下一次继续遇到元素3,那么下标的位置就变为了13      一直重复此步骤,直到元素3对应的下标位置10--14被填满
	//其他所有的元素按照上文逻辑,类推

	for (int j = lenght; j > 0; j--) {
		sort[--count[arr[j - 1]]] = arr[j - 1];
	}

	for (int o = 0; o < 100; o++) {
		//printf("%d ", sort[o]);
	}
}
