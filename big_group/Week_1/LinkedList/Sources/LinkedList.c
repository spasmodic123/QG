#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "LinkedList.h"


LinkedList init_link(LinkedList L)//初始化单向链表
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
	L->next = NULL;
	return L;
}


LinkedList_two_way init_link_two_way(LNode_two_way* L)//初始化双向链表
{
	LinkedList_two_way head_two_way = (LinkedList_two_way)malloc(sizeof(LNode_two_way));
	assert(head_two_way!=NULL);
	head_two_way->next = NULL;
	head_two_way->front = NULL;
}


Status destroy_list(LNode* L)//销毁链表
{
	if (L=NULL || L->next == NULL) {
		printf("������,��������\n");
		system("pause");
		return ERROR;
	}
	LinkedList p1 = L;
	while (p1){  //p1һֱ�������,p2����freeÿһ�����
		LinkedList p2 = p1;
		p1 = p1->next;
		free(p1);
		p1 = NULL;

		if (p1 == NULL) {
			return OK;
		}
	}
}


Status delete_list(LNode* L, ElemType e)//删除链表的某一个结点
{
	if (L=NULL || L->next == NULL) {
		printf("������,����ɾ��ĳһ�����\n");
		system("pause");
		return ERROR;
	}
	LinkedList p1 = L;
	while (p1)
	{
		p1 = p1->next;
		if (p1->data == e) {
			break;
		}
	}
	if (p1 == NULL) {//û�ж�Ӧ��Ԫ��e
		printf("��������Ҫɾ����Ԫ��!\n");
		system("pause");
		return ERROR;
	}
	LinkedList p2 = p1;//p2������Ҫɾ����Ԫ��
	p1 = p1->next;
	free(p2);
	p2 = NULL;

	return OK;
}


Status insert_list(LNode* L, int position, ElemType e)//插入结点
{
	if (L==NULL || L->next == NULL) {
		printf("������,���ɲ�����\n");
		system("pause");
		return ERROR;
	}

	LinkedList p1 = L;
	LNode *new = (LNode*)malloc(sizeof(LNode));//�����½ڵ���Ԫ��e
	new->data = e;
	for (int i = 0; i < position; i++) {
		p1 = p1->next;
		if (p1 == NULL) {
			printf("position ����������Χ!");
			system("pause");
			return ERROR;
		}
	}

	LinkedList p2 = p1;
	p1 = p1->next;
	p2->next = new;//���Ӳ���Ľ��
	new->next = p1;

	return OK;
}


Status traverse_list(LNode* L)//遍历单向链表
{
	LinkedList p1 = L;
	if (p1==NULL || p1->next == NULL) {
		printf("������,���ɴ�ӡ\n");
		system("pause");
		return ERROR;
	}

	while (p1!=NULL){
		printf("%d\t", p1->data);
		p1 = p1->next;
	}
	system("pause");
	return OK;
}


Status traverse_two_way_list(LinkedList_two_way* L)//遍历双向链表
{
	LinkedList_two_way p = L;
	if (p == NULL || p->next == NULL) {
		printf("������,���ɴ�ӡ\n");
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


Status search_list(LNode* L, ElemType e)//查找链表的某一个结点
{
	if (L==NULL || L->next == NULL) {
		printf("������,���ɲ���\n");
		system("pause");
		return ERROR;
	}
	LinkedList p = L;
	int num = 0;
	while (p->data != e) {
		p = p->next;
		num++;
		if (p->data == e) {
			printf("%d �ڵ�%d �����\n", e, num);
			system("pause");
			return OK;
		}
		if (p == NULL) {
			printf("������û�и�Ԫ��");
			system("pause");
			return ERROR;
		}
	}
}


LinkedList reverse_list_recur(LNode* L)//递归,反转链表
{
	LinkedList p, p_tmp, new_head;
	p = p_tmp = new_head = L;
	if (L == NULL || L->next == NULL) {
		printf("������,���ɷ�ת\n");
		system("pause");
		return ERROR;
	}
	new_head = NULL;
	while (p) {
		p_tmp = p->next;
		p->next = new_head;
		new_head = p;
		p = p_tmp;
	}
	return new_head;
}


LinkedList reverse_list_interation(LNode* head)//迭代,反转链表
{
	if (head == NULL || head->next == NULL) {
		return head;
	}
	LinkedList new_head = reverse_list_interation(head->next);
	head->next->next = head;
	head->next = NULL;

	return new_head;
}


Status is_loop_list(LNode* L)//判断成环
{
	LinkedList p = L;
	if (p == NULL || p->next == NULL) {
		printf("������,���ɻ�\n");
		system("pause");
		return ERROR;
	}
	LinkedList p1, p2;
	p1 = p2 = L;
	while (p1->next != NULL) {//����ָ��
		p1 = p1->next;
		p2 = p2->next->next;
		if (p1 == p2) {
			printf("�����ɻ�!");
			system("pause");
		}
	}
}


Status reversr_even_list(LNode* L)//奇数偶数项替换
{
	LinkedList p = L;
	LinkedList p1=NULL;
	LinkedList p2 = NULL;
	if (p == NULL || p->next == NULL) {
		printf("������,������ż��ת!");
		system("pasue");
		return ERROR;
	}
	int num01, num02;
	num01 = 0; num02 = 0;
	while (p != NULL) {
		if (p->data % 2 == 0) {//p1,num01��������ż��
			p1 = p;
			num01 = p1->data;
		}
		else if (p->data % 2 != 0) {//p2,num02������������
			p2 = p;
			num02 = p2->data;
		}

		if (num01 != 0 && num02 != 0) {//һ��������һ��ż�������ҵ���ʱ��,��ʼ����;
			int tmp = p2->data;
			p2->data = p1->data;
			p1->data = tmp;
			num01 = 0; num02 = 0;//����num01��num02��ֵ
		}
		p=p->next;
	}
	printf("��ż�����ɹ�!");
	system("pause");
	return OK;
}


Status find_mid_node(LNode* L) {//返回中间结点
	LinkedList p1, p2;
	p1 = L; p2 = L;
	if (p1 == NULL || p1->next == NULL) {
		printf("������,�������м���!");
		system("pasue");
		return ERROR;
	}
	while (p2 != NULL && p2->next != NULL) {
		p1 = p1->next;
		p2 = p2->next->next;
	}
	printf("�м���Ϊ %d", p1->data);
	system("pause");
}


Status create_one_way_list(LNode* L)//创建单向链表
{
	printf("����0�����������!\n");
	LinkedList p1 = L;
	LinkedList p2 = L;
	while (p1->next != NULL) {//�ҵ�Ŀǰ���������һ�����
		p1 = p1->next;
		p2 = p1;
	}
	while (1) {
		p1 = (LinkedList)malloc(sizeof(LNode));
		printf("������һ������:");
		scanf("%d", &p1->data);
		if (p1->data == 0) {
			free(p1);
			p1 = NULL;
			p2->next = NULL;
			return OK;
		}
		p2->next = p1;
		p2 = p1;
	}
	p2->next = NULL;
	printf("���ӳɹ�!");
	system("pause");
	return OK;
}



Status create_two_way_list(LNode_two_way* L)//创建双向链表
{
	printf("����0���������!\n");
	while (1) {
		LinkedList_two_way head = L;//����һ����ʱͷָ��
		if (head->next == NULL) {
			//��˫������ֻ��һ��ͷ�ڵ�ʱ
			LinkedList_two_way new_node = (LinkedList_two_way)malloc(sizeof(LNode_two_way));
			printf("������һ������:");
			scanf("%d", &new_node->data);
			if (new_node->data == 0) {
				free(new_node);
				new_node = NULL;
				printf("���ӽ���");
				system("pause");
				return OK;
			}
			new_node->next = NULL;
			new_node->front = head;
			head->next = new_node;
		}
		else {
			//��˫������������ͷ�ڵ��ʱ��
			LinkedList_two_way new_node = (LinkedList_two_way)malloc(sizeof(LNode_two_way));
			printf("������һ������:");
			scanf("%d", &new_node->data);
			if (new_node->data == 0) {
				free(new_node);
				new_node = NULL;
				printf("���ӽ���");
				system("pause");
				return OK;
			}
			head->next->front = new_node;//ͷ�ڵ����һ������front���ָ���µĽ��
			new_node->next = head->next;//�½ڵ����һ�����  ��  ԭ����ͷ�ڵ����һ�����
			new_node->front = head;//�½ڵ��front�����ͷ���
			head->next = new_node;//ͷ�ڵ����һ�����Ϊ�½ڵ�,�������Ԫ�صĲ���
		}
	}
}



LinkedList create_loop_list(LNode* L)//创建环状链表
{
	LinkedList loop_point = L;//�ɻ�,���������Ľ��
	LinkedList p1,p2 = L;
	while (1) {
		p1 = (LinkedList)malloc(sizeof(LNode));
		printf("������һ������ (����0��������):");
		scanf("%d", &p1->data);
		if (p1->data == 0) {
			free(p1);
			p1 = NULL;
			p2->next = L->next;//��ͷ�����������,�γɻ�״
			printf("���ӳɹ�!");
			system("pause");
			return OK;
		}
		p2->next = p1;
		p2 = p1;
	}

	return L;
}
