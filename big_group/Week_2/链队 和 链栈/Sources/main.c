#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include "link_queue.h"
#include "link_stack.h"

extern LinkStack S = NULL;
extern LQueue* Q = NULL;

int main()
{
	S = (LinkStack)malloc(sizeof(StackNode));
	Q = (QueueNode*)malloc(sizeof(QueueNode));
	initLStack(S);//初始化链栈
	initLQueue(Q);//初始化链队

	while (1)
	{
		system("cls");
		printf("\n\n\n---------------------------\n");
		printf(">>> 1.入栈.               \n");
		printf(">>> 2.出栈.               \n");
		printf(">>> 3.销毁链栈.           \n");
		printf(">>> 4.获取链栈长度.              \n");
		printf(">>> 5.获取链栈顶元素.              \n");
		printf(">>> 6.判断链栈是否为空.              \n\n\n\n");
		printf(">>> 7.入队             \n");
		printf(">>> 8.出队.    \n");
		printf(">>> 9.获取队列头元素.       \n");
		printf(">>> 10.清空队列         \n");
		printf(">>> 11.销毁队列.  \n");
		printf(">>> 12.判断队列是否为空               \n");
		printf(">>> 13.遍历队列               \n");
		printf(">>> 14.获取队列长度              \n\n\n\n");
		printf(">>> 15.退出程序               \n");
		printf("---------------------------\n");

		int num; char c;
		printf("请输入你的选择:");
		int ret = scanf("%d", &num);//scanf函数的返回值为成功读取的元素的个数,如果是%d,你却输入了一个字母,那么成功读取数目为0
		if (ret < 1) {
			while ((c = getchar()) != EOF && c != '\n');//利用getchar函数,不断读取,清除缓存区域
			printf("输入非法!!!请重新输入   \033[31m应该输入一个整数 \033[0m\n");
			system("pause");
		}
		switch (num)
		{
		case 1:
			S=pushLStack(S);
			break;
		case 2:
			S = popLStack(S);
			break;
		case 3:
			S=destroyLStack(S);
			break;
		case 4:
			LStackLength(S);
			break;
		case 5:
			getTopLStack(S);
			break;
		case 6:
			isEmptyLStack(S);
			break;
		case 7:
			EntryQueue(Q);
			break;
		case 8:
			OutQueue(Q);
			break;
		case 9:
			GetFrontQueue(Q);
			break;
		case 10:
			ClearQueue(Q);
			break;
		case 11:
			DestoryQueue(Q);
			break;
		case 12:
			isEmptyQueue(Q);
			break;
		case 13:
			TraverseLQueue(Q);
			break;
		case 14:
			LenghtQueue(Q);
			break;
		case 15:
			return 0;
		default:
			break;
		}
	}
}
