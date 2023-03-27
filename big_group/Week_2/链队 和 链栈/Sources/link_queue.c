#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "link_queue.h"
#include "link_stack.h"


Status initLQueue(LQueue* Q)//初始化队列
{
	if (! (Q->front = Q->rere = (QueueNode*)malloc(sizeof(QueueNode))) )//头尾节点指向同一结点
		exit(OVERFLOW);
	Q->front->next= NULL;
	return OK;
}



Status isEmptyQueue(LQueue* Q)//判断队列是否为空
{
	if (Q->front == Q->rere) {
		printf("空链队!\n");
		system("pause");
		return ERROR;
	}
	else {
		printf("链队不为空!\n");
		system("pause");
	}
}


char _tmp[50000];//设置一个缓冲区,放字符串(还有就是安全性起见,开辟了足够大的空间,无论字符串多长,都不会爆掉)
Status EntryQueue(LQueue* Q)//入队
{
	system("cls");
	printf("\t\t\t\t\t\t\033[33m入队功能 \033[0m\n\n");
	printf("  ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");

	int num; char c;

	while(1)
	{
		QueueNode* new_q = (QueueNode*)malloc(sizeof(QueueNode));//创建新的结点
		printf("请输入你要添加的元素类型    1/整型    2/字符    3/字符串:   (输入0停止入队)");//先选择想要添加数据的类型,通过switch函数各自对应
		int ret = scanf("%d", &num);
		if (ret < 1 || num>3 || num < 0) {//判断输入是否合法
			while ((c = getchar()) != EOF && c != '\n');
			printf("输入非法!!!请重新输入   \033[31m应该输入一个1~~~3的整数 \033[0m\n\n");
		}

		switch (num)
		{
		case 1:{//整数
			int *tmp = malloc(sizeof(int));
			while(1)
			{
				printf("请输入整数:");
				ret = scanf("%d", tmp);
				if (ret < 1 ) {//判断输入是否合法,合法就储存变量,不合法就重新输入
					while ((c = getchar()) != EOF && c != '\n');
					printf("输入非法!!!请重新输入   \033[31m应该输入一个整数 \033[0m\n\n");
				}
				else { new_q->data = tmp; 
				new_q->flag = 1; break; }//flag是一个标记,1代表data储存的是整数,2代表字符,3代表字符串
			}
			break;
		}
		case 2:{
			char tmp[50];
			char *ch=malloc(sizeof(char));
			while(1){
				printf("请输入你想要添加的字符:");
				scanf("%s",tmp);
				if (strlen(tmp) > 1) {
					strcpy(tmp, "\0");
					printf("输入非法!!!请重新输入   \033[31m应该输入一个字符,而不是多个 \033[0m\n\n");//单个字符,不是字符串,加以判断
				}
				else {
					*ch = tmp[0];
					new_q->data = ch;
					new_q->flag = 2;//flag是一个标记,1代表data储存的是整数,2代表字符,3代表字符串
					break;
				}
			}
			break;
		}
		case 3: {

			printf("请输入你想要添加的字符串:");
			scanf("%s", _tmp);
			char* tmp = malloc(sizeof(char) * (strlen(_tmp) + 1));//strlen函数判断字符串有多长,输入多长,就分配多少内存
			memcpy(tmp, _tmp, sizeof(char) * (strlen(_tmp) + 1));
			new_q->data = tmp;
			new_q->flag = 3;//flag是一个标记,1代表data储存的是整数,2代表字符,3代表字符串
			break;
		}
		default:
			break;
		}
		if (num == 0) {//结束入队
			free(new_q);
			new_q = NULL;
			printf("入队成功!\n");
			system("pause");
			return OK;
		}
		
		new_q->next = NULL;//一般入队操作
		Q->rere->next = new_q;
		Q->rere = new_q;
	}

}



Status OutQueue(LQueue* Q, void (*foo)(void* q))//出队
{
	system("cls");
	printf("\t\t\t\t\t\t\033[33m出队功能 \033[0m\n\n");
	printf("  ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");

	QueueNode* q_free = (QueueNode*)malloc(sizeof(QueueNode));
	q_free = Q->front->next;//指向链队的队头
	if (Q->front == Q->rere) {//空链队
		printf("链队为空,不可出队!\n");
		system("pause");
		return ERROR;
	}
	if (q_free == Q->rere) {//出队的结点刚好是队尾
		Q->rere = Q->front;//把队尾结点,重新设置为front结点,变为空队
		printf("出队成功,出队的元素为:   \n");
		LPrint(q_free);
		free(q_free);
		q_free = NULL;
		system("pause");
		return OK; 
	}
	else {
		Q->front->next = q_free->next;
		printf("出队成功!出队的元素为    \n");
		LPrint(q_free);
		free(q_free);
		q_free = NULL;
		system("pause");
		return OK;
	}
}



Status GetFrontQueue(LQueue* Q)//获取队列第一个元素
{
	QueueNode* q = (QueueNode*)malloc(sizeof(QueueNode));
	q = Q->front->next;
	if (Q->front->next == NULL) {
		printf("空链队,不存在队头元素");
		system("pause");
		return ERROR;
	}
	else{
		printf("队头元素为:");
		LPrint(q);
		system("pause");
		return OK;
	}
}



Status LenghtQueue(LQueue* Q)//获取队列长度
{
	if (!isEmptyQueue(Q)) {//判断是否为空
		int count=0;
		QueueNode* q = (QueueNode*)malloc(sizeof(QueueNode));
		q = Q->front->next;
		while (q != NULL) {
			count++;
			q = q->next;
		}
		printf("链队长度为  %d\n", count);
		system("pause");
		return OK;
	}
}



QueueNode* DestoryQueue(LQueue* Q)//销毁队列
{
	system("cls");
	printf("\t\t\t\t\t\t\033[33m销毁链队功能 \033[0m\n\n");
	printf("  ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");

	QueueNode* q_free = (QueueNode*)malloc(sizeof(QueueNode));
	q_free = Q->front->next;//接收队头
	while (q_free!= NULL) {//与清空链队的区别在于,销毁连着头节点一并删除

		Q->front->next = q_free->next;//队头后移
		free(q_free);//释放
		q_free = NULL;
		q_free = Q->front->next;
	}
	Q->rere = Q->front;//队尾和对头指向同一结点
	printf("链队销毁完成!\n");

	QueueNode* new_queue = (QueueNode*)malloc(sizeof(QueueNode));//销毁之后,自动创建并初始化!
	initLQueue(new_queue);
	return new_queue;
	system("pause");
}



Status ClearQueue(LQueue* Q)//清空队列
{
	system("cls");
	printf("\t\t\t\t\t\t\033[33m清空链队功能 \033[0m\n\n");
	printf("  ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");

	QueueNode* q_free = (QueueNode*)malloc(sizeof(QueueNode));
	q_free = Q->front->next;//接收队头
	while(q_free->next!=NULL){

		Q->front->next = q_free->next;//队头后移
		free(q_free);//释放
		q_free = NULL;
		q_free = Q->front->next;
	}
	Q->rere = Q->front;//队尾和对头指向同一结点
	printf("队列清空完成!\n");
	system("pause");
	return OK;
}



Status TraverseLQueue(LQueue*Q)//遍历队列
{
	system("cls");
	printf("\t\t\t\t\t\t\033[33m遍历链队功能 \033[0m\n\n");
	printf("  ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");

	QueueNode* q = (QueueNode*)malloc(sizeof(QueueNode));
	if (Q->front->next == NULL) {
		printf("空链队,不可遍历!\n");
		system("pause");
		return ERROR;
	}
	for (q = Q->front->next; q; q = q->next) {
		LPrint(q);//打印
	}
	printf("遍历完成!\n");
	system("pause");
	return OK;
}



void LPrint(QueueNode* p)//定义一个打印函数,根据data类型不同,选择不同的打印方式
{
	if (p->flag == 1) {
		printf("%d    ", *(int*)(p->data) );//flag==1,整形    2,字符    3,字符串
	}
	else if (p->flag == 2) {
		printf("%c    ", *(char*)(p->data));
	}
	else {
		printf("%s    ", (char*)(p->data));	
	}
}
