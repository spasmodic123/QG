#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "LinkedList.h"

extern LinkedList loop_head;
extern LinkedList head_one_way;
extern LinkedList_two_way head_two_way;


LinkedList init_link(LinkedList L)
{
	if (!L) // Judge if the head node exists
	{
		return ERROR;
	}
	L = (LinkedList)malloc(sizeof(LNode)); // Allocate memory for the head node
	if (L == NULL) // Judge if memory is sufficient
	{
		return OVERFLOW;
	}
	printf("Successfully initialize the LinkedList.\n");
	L->data = 0;
	L->next = NULL;
	return L;
}


LinkedList_two_way init_link_two_way(LNode_two_way* L)
{
	LinkedList_two_way head_two_way = (LinkedList_two_way)malloc(sizeof(LNode_two_way));
	assert(head_two_way!=NULL);
	head_two_way->data = 0;
	head_two_way->next = NULL;
	head_two_way->front = NULL;
}


Status destroy_list(LNode* L)
{
	LinkedList p1 = L;
	if (L=NULL || L->next == NULL) {
		printf("空链表,不可销毁\n");
		system("pause");
		return ERROR;
	}

	//LinkedList p1 = L; //这一句千万不可以与上面那一句LinkedList p1 = L; 交换位置,因为判断时候,L指针已经往后移动,再次p1接收L,接收的的不是头指针

	while (1){  //p1一直往后遍历,p2负责free每一个结点
		LinkedList p2 = p1;
		p1 = p1->next;
		free(p2);
		p2 = NULL;

		if (p1 == NULL) {
			head_one_way = init_link(head_one_way);//初始化
			printf("删除成功!");
			system("pause");
			return OK;
		}
	}
}


Status delete_list(LNode* L, ElemType e)
{
	LinkedList p1 = L;

	if (L=NULL || L->next == NULL) {
		printf("空链表,不可删除某一个结点\n");
		system("pause");
		return ERROR;
	}
	while (1)
	{
		if (p1->next == NULL) {//没有对应的元素e
			printf("\n不存在所要删除的元素(8)!\n");
			system("pause");
			return ERROR;
		}
		if (p1->next->data == e) {
			break;
		}

		p1 = p1->next;

	}
	LinkedList p2 = p1;//p2接收需要删除的元素 的前一个元素
	p1 = p1->next;//此时p1为需要删除的结点
	p2->next = p1->next;//绕过需要删除的节点,将链表连接
	free(p1);//删除操作
	p1 = NULL;

	printf("\n成功删除元素8");
	system("pause");
	return OK;
}


Status insert_list(LNode* L, int position, ElemType e)
{
	if (L==NULL || L->next == NULL) {
		printf("\n空链表,不可插入结点\n");
		system("pause");
		return ERROR;
	}

	LinkedList p1 = L;
	LNode *new = (LNode*)malloc(sizeof(LNode));//创建新节点存放元素e
	new->data = e;
	for (int i = 0; i < position; i++) {
		p1 = p1->next;
		if (p1 == NULL) {
			printf("\nposition 超出链表范围!");
			system("pause");
			return ERROR;
		}
	}

	LinkedList p2 = p1;
	p1 = p1->next;
	p2->next = new;//连接插入的结点
	new->next = p1;

	return OK;
}


Status traverse_list(LNode* L)
{
	LinkedList p1 = L;
	if (p1==NULL || p1->next == NULL) {
		printf("\n空链表,不可打印\n");
		system("pause");
		return ERROR;
	}
	p1 = L;
	while (p1!=NULL){
		printf("%d\t", p1->data);
		p1 = p1->next;
	}
	printf("\n遍历完成!");
	system("pause");
	return OK;
}


Status traverse_two_way_list(LinkedList_two_way* L)
{
	LinkedList_two_way p = L;
	if (p == NULL || p->next == NULL) {
		printf("\n空链表,不可打印\n");
		system("pause");
		return ERROR;
	}
	while (p != NULL) {
		printf("%d\t", p->data);
		p = p->next;
	}
	system("pause");
	return OK;
}


Status search_list(LNode* L, ElemType e)
{
	LinkedList p = L;
	if (L==NULL || L->next == NULL) {
		printf("\n空链表,不可查找\n");
		system("pause");
		return ERROR;
	}
	int num = 0;
	while (p->data != e) {
		p = p->next;
		num++;
		if (p == NULL) {
			printf("\n链表中没有元素(9)");
			system("pause");
			return ERROR;
		}
		if (p->data == e) {
			printf("\n%d 在第%d 个结点\n", e, num);
			system("pause");
			return OK;
		}
	}
}


LinkedList reverse_list_recur(LNode* L)
{
	LinkedList p, p_tmp, new_head;
	p = p_tmp = new_head = L;
	if (L == NULL || L->next == NULL) {
		printf("\n空链表,不可翻转\n");
		system("pause");
		return ERROR;
	}
	new_head = NULL;//原来的头指针反转后变成尾部,设为null  (换句话说,new_head充当上一个结点的作用)
	while (p) {
		p_tmp = p->next;//使一个指针后移
		p->next = new_head;//使该指针连接上一个结点
		new_head = p;
		p = p_tmp;
	}
	printf("\n反转成功!");
	system("pause");
	return new_head;
}


LinkedList reverse_list_interation(LNode* head)
{
	if (head == NULL || head->next == NULL) {
		return head;
	}
	LinkedList new_head = reverse_list_interation(head->next);
	head->next->next = head;
	head->next = NULL;

	return new_head;
}


Status is_loop_list(LNode* L)
{
	LinkedList p = L;
	if (p == NULL || p->next == NULL) {
		printf("\n空链表,不成环\n");
		system("pause");
		return ERROR;
	}
	LinkedList p1, p2;
	p1 = p2 = L;
	while (p1->next != NULL) {//快慢指针
		p1 = p1->next;
		p2 = p2->next->next;
		if (p1 == p2) {
			printf("\n链表成环!");
			system("pause");
			return OK;
		}
	}
}


Status reversr_even_list(LNode* L)
{
	LinkedList p = L;
	LinkedList p1=NULL;
	LinkedList p2 = NULL;
	if (p == NULL || p->next == NULL) {
		printf("\n空链表,不能奇偶反转!");
		system("pasue");
		return ERROR;
	}
	int num01, num02;
	num01 = 0; num02 = 0;
	while (p != NULL) {
		if (p->data % 2 == 0) {//p1,num01用来接收偶数
			p1 = p;
			num01 = p1->data;
		}
		else if (p->data % 2 != 0) {//p2,num02用来接收奇数
			p2 = p;
			num02 = p2->data;
		}

		if (num01 != 0 && num02 != 0) {//一个奇数和一个偶数都被找到的时侯,开始交换;
			int tmp = p2->data;
			p2->data = p1->data;
			p1->data = tmp;
			num01 = 0; num02 = 0;//重置num01和num02的值
		}
		p=p->next;
	}
	printf("\n奇偶调换成功!");
	system("pause");
	return OK;
}


Status find_mid_node(LNode* L) {
	LinkedList p1, p2;
	p1 = L; p2 = L;
	if (p1 == NULL || p1->next == NULL) {
		printf("\n空链表,不存在中间结点!");
		system("pasue");
		return ERROR;
	}
	while (p2 != NULL && p2->next != NULL) {
		p1 = p1->next;
		p2 = p2->next->next;
	}
	printf("\n中间结点为 %d", p1->data);
	system("pause");
}


Status create_one_way_list(LNode* L)
{
	printf("输入0代表输入结束!\n");
	LinkedList p1 = L;
	LinkedList p2 = L;
	while (p1->next != NULL) {//找到目前链表的最后一个结点
		p1 = p1->next;
		p2 = p1;
	}
	while (1) {
		p1 = (LinkedList)malloc(sizeof(LNode));
		printf("请输入一个整数:");
		scanf("%d", &p1->data);
		if (p1->data == 0) {
			free(p1);
			p1 = NULL;
			p2->next = NULL;
			printf("\n添加成功!");
			system("pause");
			return OK;
		}
		p2->next = p1;
		p2 = p1;
	}
	return OK;
}



LinkedList_two_way create_two_way_list(LNode_two_way* L)
{
	printf("输入0则输入结束!\n");
	while (1) {
		LinkedList_two_way head = L;//创建一个临时头指针
		if (head->next == NULL) {
			//当双向链表只有一个头节点时
			LinkedList_two_way new_node = (LinkedList_two_way)malloc(sizeof(LNode_two_way));
			printf("请输入一个整数:");
			scanf("%d", &new_node->data);
			if (new_node->data == 0) {
				free(new_node);
				new_node = NULL;
				printf("\n添加结束");
				system("pause");
				return OK;
			}
			new_node->next = NULL;
			new_node->front = head;
			head->next = new_node;
		}
		else {
			//当双向链表有两个头节点的时候
			LinkedList_two_way new_node = (LinkedList_two_way)malloc(sizeof(LNode_two_way));
			printf("请输入一个整数:");
			scanf("%d", &new_node->data);
			if (new_node->data == 0) {
				free(new_node);
				new_node = NULL;
				printf("\n添加结束");
				system("pause");
				return OK;
			}
			head->next->front = new_node;//头节点的下一个结点的front结点指向新的结点
			new_node->next = head->next;//新节点的下一个结点  是  原来的头节点的下一个结点
			new_node->front = head;//新节点的front结点是头结点
			head->next = new_node;//头节点的下一个结点为新节点,完成添加元素的操作
		}
	}
}



LinkedList create_loop_list(LNode* L)
{
	LinkedList loop_point = L;//成环,连接起来的结点
	LinkedList p1,p2 = L;
	while (1) {
		p1 = (LinkedList)malloc(sizeof(LNode));
		printf("请输入一个整数 (输入0代表结束):");
		scanf("%d", &p1->data);
		if (p1->data == 0) {
			free(p1);
			p1 = NULL;
			p2->next = L;//跟头结点连接起来,形成环状
			//traverse_list(L);
			printf("\n添加成功!");
			system("pause");
			return L;
		}
		p2->next = p1;
		p2 = p1;
	}

}