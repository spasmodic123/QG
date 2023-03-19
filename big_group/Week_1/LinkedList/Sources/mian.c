#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "LinkedList.h"


int main()
{
	LinkedList head_one_way = (LinkedList)malloc(sizeof(LNode)); // 单向链表的头指针
	LinkedList_two_way head_two_way = (LinkedList_two_way)malloc(sizeof(LNode_two_way));//双向链表头指针
	LinkedList loop_head = (LinkedList)malloc(sizeof(LNode));//成环链表头指针

	head_one_way = init_link(head_one_way);//初始化
	head_two_way = init_link_two_way(head_two_way);
    loop_head = init_link(loop_head);

	while (1)
	{
		system("cls");
		printf("\n\n\n---------------------------\n");
		printf(">>> 1.创建单向链表.               \n");
		printf(">>> 2.创建双向链表.               \n");
		printf(">>> 3.销毁单向链表.           \n");
		printf(">>> 4.往单向链表加入元素.              \n");
		printf(">>> 5.查找单向链表里的某一个元素.              \n");
		printf(">>> 6.删除单向链表的某一个元素.              \n");
		printf(">>> 7.遍历单向链表.             \n");
		printf(">>> 8.遍历双向链表.    \n");
		printf(">>> 9.反转单向链表(  递归  ).       \n");
		printf(">>> 10.反转单向链表(  迭代  )         \n");
		printf(">>> 11.单向链表奇偶项调换.  \n");
		printf(">>> 12.判断链表是否成环(  确保判断之前先用选项14创建成环链表  )               \n");
		printf(">>> 13.寻找单向链表中间结点               \n");
		printf(">>> 14.创建一个成环的链表              \n");
		printf(">>> 15.退出程序               \n");
		printf("---------------------------\n");

		int num;
		printf("请输入你的选择:");
		scanf("%d", &num);
		switch (num)
		{
		case 1:
			create_one_way_list(head_one_way);
			break;
		case 2:
			create_two_way_list(head_two_way);
			break;
		case 3:
			destroy_list(head_one_way);
			break;
		case 4:
			insert_list(head_one_way, 3, 666);//第三个结点位置插入data=666的元素
			break;
		case 5:
			search_list(head_one_way, 9);//寻找单向链表中是否有data=9这个元素
			break;
		case 6:
			delete_list(head_one_way, 8);//删除单向链表里data=8这个元素
			break;
		case 7:
			traverse_list(head_one_way);
			break;
		case 8:
			traverse_two_way_list(head_two_way);
			break;
		case 9:
			reverse_list_recur(head_one_way);
			break;
		case 10:
			reverse_list_interation(head_one_way);
			break;
		case 11:
			reversr_even_list(head_one_way);
			break;
		case 12:
			is_loop_list(loop_head);
			break;
		case 13:
			find_mid_node(head_one_way);
			break;
		case 14:
			loop_head=create_loop_list(loop_head);
			break;
		case 15:
			return 0;
		default:
			break;
		}
	}
}
