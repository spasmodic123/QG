#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>
#include"b_tree.h"

int main()
{
	tree_node T=(tree_node)malloc(sizeof(BTree));
	T = InitBRree(T); 
	while (1)
	{
		system("cls");
		printf("\n\n\n---------------------------\n");
		printf(">>> 1.插入结点.               \n");
		printf(">>> 2.递归先序遍历.               \n");
		printf(">>> 3.递归中序遍历.           \n");
		printf(">>> 4.递归后序遍历.              \n");
		printf(">>> 5.非递归先序遍历.              \n");
		printf(">>> 6.非递归中序遍历.              \n\n\n\n");
		printf(">>> 7.非递归后序遍历.             \n");
		printf(">>> 8.查找结点.    \n");
		printf(">>> 9.层次遍历.    \n");
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
			insert_node(T);
			break;
		case 2:
			pre_order(T);	system("pause");
			break;
		case 3:
			mid_order(T); system("pause");
			break;
		case 4:
			post_order(T); system("pause");
			break;
		case 5:
			ppre_order_iteration(T); system("pause");
			break;
		case 6:
			mid_order_iteration(T); system("pause");
			break;
		case 7:
			post_order_iteration(T); system("pause");
			break;
		case 8:
			system("cls");
			printf("\t\t\t\t\t\t\033[33m查找结点功能 \033[0m\n\n");
			printf("  ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
			tree_node tmp = (tree_node)malloc(sizeof(BTree));
			tmp = find_value(T);
			if (tmp == NULL) {
				printf("不存在该元素!"); system("pause");
			}
			else {
				printf("%d 元素存在!", tmp->data);
				system("pause");
			}
			break;
		case 9:
			level_order(T); system("pause");
			break;
		case 15:
			return 0;
		default:
			break;
		}
	}
	return 0;
}


