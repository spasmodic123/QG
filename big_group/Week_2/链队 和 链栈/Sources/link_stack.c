#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include "link_stack.h"

extern LinkStack S;

Status initLStack(LinkStack S)//初始化栈
{
	if (S == NULL) {
		printf("内存分配失败");
		system("pause");
		return ERROR;
	}
	S->next = NULL;
	return OK;
}


Status isEmptyLStack(LinkStack S)//判断栈是否为空
{
	if (S->next == NULL) {
		printf("链栈为空!\n");
		system("pause");
		return OK;
	}
	else {
		printf("链栈不为空!\n");
		system("pause");
		return OK;
	}
}


Status getTopLStack(LinkStack S)//得到栈顶元素
{
	system("cls");
	printf("\t\t\t\t\t\t\033[33m获取栈顶元素功能 \033[0m\n\n");
	printf("  ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
	LinkStack pnew = (LinkStack)malloc(sizeof(StackNode));
	pnew = S;
	if (S->next == NULL) {
		printf("空链栈,不存在栈顶元素!\n");
		system("pause");
		return ERROR;
	}
	printf("栈顶元素为 %d ", pnew->data);
	system("pause");
	return OK;
}


LinkStack destroyLStack(LinkStack S)//销毁栈
{
	system("cls");
	printf("\t\t\t\t\t\t\033[33m销毁栈功能 \033[0m\n\n");
	printf("  ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
	LinkStack pnew = (LinkStack)malloc(sizeof(StackNode));
	pnew = S;
	if (S->next == NULL) {
		printf("空链栈,无需销毁!\n"); system("pause");
		return S;
	}
	while (pnew != NULL){
		S = S->next;
		free(pnew);
		pnew = NULL;
		pnew = S;
	}
	printf("销毁成功!\n");
	S = (LinkStack)malloc(sizeof(StackNode));//销毁链栈后,原本的链栈已经不存在,需要重新创建并且初始化
	initLStack(S);//初始化链栈
	system("pause");
	return S;
}


Status LStackLength(LinkStack S)//检测链栈长度
{
	system("cls");
	printf("\t\t\t\t\t\t\033[33m检测链栈长度功能 \033[0m\n\n");
	printf("  ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
	int count = 0;
	while (S != NULL) {
		S = S->next;
		count ++ ;
	}
	printf("链栈的长度为 %d ", count-1);//减去1,因为计算时将初始化后存在的,原本不存数据的头节点也算进去了
	system("pause");
	return OK;
}


LinkStack pushLStack(LinkStack S)//入栈
{
	system("cls");
	printf("\t\t\t\t\t\t\033[33m入栈功能 \033[0m\n\n");
	printf("  ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
	char c; int num;
	while(1)
	{
		LinkStack pnew = (LinkStack)malloc(sizeof(StackNode));
		printf("请输入一个整数  (输入数字0入栈停止!):");//先判断输入是否合法
		int ret = scanf("%d", &num);//scanf函数的返回值为成功读取的元素的个数,如果是%d,你却输入了一个字母,那么成功读取数目为0
		if (ret < 1) {
			while ((c = getchar()) != EOF && c != '\n');//利用getchar函数,不断读取,清除缓存区域
			printf("输入非法!!!请重新输入   \033[31m应该输入一个整数 \033[0m\n");
			system("pause");
		}
		else{//如果合法
			if (num==0) {
				free(pnew);
				pnew = NULL;
				printf("入栈成功!");
				system("pause");
				return S;
			}
			else {//因为FILO原理,采用头插法添加结点,而不是尾插
				pnew->data = num;
				pnew->next = S;
				S = pnew;
			}
		}
	}
}


LinkStack popLStack(LinkStack S)//出栈
{
	system("cls");
	printf("\t\t\t\t\t\t\033[33m出栈功能 \033[0m\n\n");
	printf("  ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
	LinkStack pnew = (LinkStack)malloc(sizeof(StackNode));
	pnew = S;
	if (pnew->next == NULL) {
		printf("空栈,不可出栈!\n");
		system("pause");
		return S;
	}
	printf("出栈的元素为 %d \n", S->data);
	S = S->next;
	free(pnew);
	pnew = NULL;
	printf("出栈成功!\n");
	system("pause");
	return S;
}
