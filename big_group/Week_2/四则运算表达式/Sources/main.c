#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calculate.h"

//10以内的加减乘除运算
int main()
{
	char before_stack[100];//刚开始输入一个字符串,先存放到第一个字符串
	char last_stack[100];//经过栈运算,转化成的后缀表达式,存放到第二个字符串
	SqStack stack_first;
	SqStack_double stack_second;
	InitStack(&stack_first);//进行中缀转化成后缀表达式的栈
	InitStack(&stack_second);//进行后缀表达式最终运算的栈

	printf("%d", GetTop(&stack_first));
	while (1)
	{
		system("cls");
		printf("\t\t\t\t\t\t\033[33m 10以内加减乘除 \033[0m\n\n");
		printf("  ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");

		int j = 0;//j为last_stack字符串的下标,里面存放着后缀表达式

		printf("\033[31m 不要存在空格 \033[0m\n\n");
		printf("\033[31m 不要存在小数 \033[0m\n\n");
		printf("\033[31m 不要输入>=10的的数 \033[0m\n\n");

		printf("请输入一个算式:\t\t示例  6+(4-2)*3+9/3\n请输入:");

		scanf("%s", before_stack);
		for (int i = 0; i < strlen(before_stack); i++) {//遍历字符串的每一个元素
			if (is_illegal(before_stack[i])) {//如果不合法
				printf("输入非法,可能有非法字母,或者有空格,或者存在小数字,请重新输入!");
				strcpy(before_stack, "\0");//清空原来字符串
				break;
			}
			else {//如果合法
				if (before_stack[i] >= '0' && before_stack[i] <= '9') {//如果是数字,直接输出,放在储存后缀表达式的字符串
					last_stack[j] = before_stack[i];//放到储存后缀表达式的字符串
					j++;
				}

				else if (before_stack[i] == '(') {//碰到左括号开始入栈
					Push(&stack_first, before_stack[i]);
				}

				else if (before_stack[i] == ')') {//碰到右括号就一直出栈,直到左括号
					while (GetTop(&stack_first) != '(') {//不遇到左括号就一直出
						char ch = Pop(&stack_first);//但是括号不参与最终运算,不应该存放在第二个字符串,只有数字和普通运算符才放到第二个字符串中
						last_stack[j] = ch;
						j++;
					}
					Pop(&stack_first);//遇到了左括号,就把左括号去掉
				}

				else {//运算符号优先级的判断
					if (big_or_small(before_stack[i], GetTop(&stack_first))) {//判断运算符优先级
						Push(&stack_first, before_stack[i]);//大于就入栈
					}
					else {//小于就一直出栈
						while (1) {
							char ch = Pop(&stack_first);
							last_stack[j] = ch;
							j++;
							if (big_or_small(before_stack[i], GetTop(&stack_first))) {//出栈之后继续比较下一个栈顶元素,如果大于栈顶元素,就停止
								break;
							}
						}
						Push(&stack_first, before_stack[i]);//最后将当前运算符入栈
					}
				}
			}
		}
		while (GetTop(&stack_first)) {//最后将剩余的数据全部出栈,放到储存后缀表达式的字符串中
			char ch=Pop(&stack_first);
			last_stack[j] = ch;
			j++;
		}
		last_stack[j] = '\0';//字符串结束标志
		printf("后缀表达式为:%s\n", last_stack);



		//接下来是运算步骤,第二个栈登场
		for(int k=0;k<strlen(last_stack);k++){
			if (last_stack[k] >= '0' && last_stack[k] <= '9') {//如果是数字,则入栈
				double num = trans_char_to_double(last_stack[k]);//将字符转化成
				Push_number(&stack_second, num);
			}
			else {//如果是运算符,则计算栈顶的两个元素,在入栈
				double tmp1=Pop_number(&stack_second);
				double tmp2=Pop_number(&stack_second);
				if (last_stack[k] == '*') {
					Push_number(&stack_second, tmp2 * tmp1);
				}
				else if (last_stack[k] == '/') {
					Push_number(&stack_second, tmp2 / tmp1);//这里很细节,是tmp2 / tmp1,下面一个除以上面一个,而不是反过来,很细节
				}
				else if (last_stack[k] == '+') {
					Push_number(&stack_second, tmp2 + tmp1);
				}
				else if (last_stack[k] == '-') {
					Push_number(&stack_second, tmp2 - tmp1);
				}
			}
		}

		printf("最终结果为:  %lf", Pop_number(&stack_second));
		system("pause");
	}
}
