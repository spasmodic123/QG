#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "LinkedList.h"


int main()
{
	LinkedList head_one_way = (LinkedList)malloc(sizeof(LNode)); // ���������ͷָ��
	LinkedList_two_way head_two_way = (LinkedList_two_way)malloc(sizeof(LNode_two_way));//˫������ͷָ��
	LinkedList loop_head = (LinkedList)malloc(sizeof(LNode));//�ɻ�����ͷָ��

	head_one_way = init_link(head_one_way);//��ʼ��
	head_two_way = init_link_two_way(head_two_way);
    loop_head = init_link(loop_head);

	while (1)
	{
		system("cls");
		printf("\n\n\n---------------------------\n");
		printf(">>> 1.������������.               \n");
		printf(">>> 2.����˫������.               \n");
		printf(">>> 3.���ٵ�������.           \n");
		printf(">>> 4.�������������Ԫ��.              \n");
		printf(">>> 5.���ҵ����������ĳһ��Ԫ��.              \n");
		printf(">>> 6.ɾ�����������ĳһ��Ԫ��.              \n");
		printf(">>> 7.������������.             \n");
		printf(">>> 8.����˫������.    \n");
		printf(">>> 9.��ת��������(  �ݹ�  ).       \n");
		printf(">>> 10.��ת��������(  ����  )         \n");
		printf(">>> 11.����������ż�����.  \n");
		printf(">>> 12.�ж������Ƿ�ɻ�(  ȷ���ж�֮ǰ����ѡ��14�����ɻ�����  )               \n");
		printf(">>> 13.Ѱ�ҵ��������м���               \n");
		printf(">>> 14.����һ���ɻ�������              \n");
		printf(">>> 15.�˳�����               \n");
		printf("---------------------------\n");

		int num;
		printf("���������ѡ��:");
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
			insert_list(head_one_way, 3, 666);//���������λ�ò���data=666��Ԫ��
			break;
		case 5:
			search_list(head_one_way, 9);//Ѱ�ҵ����������Ƿ���data=9���Ԫ��
			break;
		case 6:
			delete_list(head_one_way, 8);//ɾ������������data=8���Ԫ��
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
