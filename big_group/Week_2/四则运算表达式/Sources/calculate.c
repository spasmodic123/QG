#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include "calculate.h"

Status InitStack(SqStack* S)//初始化顺序栈
{
	S->base = (StackElemType*)malloc(sizeof(MAXSTACK));
	if (!S->base) {
		exit(OVERFLOW);
	}
	S->top = S->base;//栈顶指向栈尾
	S->stacksize = MAXSTACK;
	return OK;
}


Status Push(SqStack* S, StackElemType e)//字符串的入栈
{
	if (S->top == S->base+S->stacksize) {//如果栈满了
		exit(OVERFLOW);
	}
	*(S->top) = e;
	S->top++;
	S->stacksize--;
	return OK;
}

Status Push_number(SqStack_double* S, double e)//数字的入栈
{
	if (S->top == S->base + S->stacksize) {//如果栈满了
		return(OVERFLOW);
	}
	*(S->top) = e;
	S->top++;
	S->stacksize--;
	return OK;
}

StackElemType Pop(SqStack* S)//字符串的出栈
{
	if (S->top == S->base) {
		return(ERROR);
	}
	S->top--;
	return *(S->top);
}

double Pop_number(SqStack_double*S)//数字的出栈
{
	if (S->top == S->base) {
		return(ERROR);
	}
	S->top--;
	return *(S->top);
}


StackElemType GetTop(SqStack* S)
{
	if (S->top == S->base) {
		return ERROR;
	}
	char c = *(S->top - 1);
	return c;//返回栈顶元素
}

int is_illegal(char ch)//判断输入是否非法,非法返回1,合法返回0
{
	if (ch >= 'a' && ch <= 'z' || ch >= "A" && ch <= "Z" || ch == ' ') {
		return 1;
	}
	else{
		return 0;
	}
}


int big_or_small(char a, char b)//判断该运算符优先级是大于栈顶元素还是小于,大于返回1,小于或等于返回0,栈顶是左括号也返回1,入栈
{
	if (a == '*' && b == '+' || b == '-') {
		return 1;
	}
	else if(a == '/' && b == '+' || b == '-') {
		return 1;
	}
	else if(b == '(') {
		return 1;
	}
	else if (b == 0) {//b==0表示已经到达栈底
		return 1;
	}
	else {
		return 0;
	}
}



double trans_char_to_double(char x)//定义一个将字符转化为数字的函数
{
	double number[10]={0.0,1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0};
	char ch[10] = { '0','1', '2' ,'3','4','5','6','7','8','9' };
	for (int i = 0; i < 10; i++) {
		if (x == ch[i]) {
			return number[i];
		}
	}
}
