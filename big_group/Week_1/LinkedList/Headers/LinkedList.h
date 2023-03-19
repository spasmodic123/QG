#define  _CRT_SECURE_NO_WARNINGS 1
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int Status;
typedef int ElemType;

typedef struct LNode {//��������
	ElemType data;
	struct LNode* next;
}LNode,*LinkedList;


typedef struct LNode_two_way {//˫������
	ElemType data;
	struct LNode_two_way* front;
	struct LNode_two_way* next;
}LNode_two_way,*LinkedList_two_way;


LinkedList init_link(LNode* L);// ��ʼ����������

LinkedList_two_way init_link_two_way(LNode_two_way* L);//��ʼ��˫������

Status destroy_list(LNode* L);//��������

Status delete_list(LNode* L,ElemType e);//ɾ�������е�ĳһ��Ԫ��

Status insert_list(LNode* L, int position, ElemType e);//��position��Ľ�������,�ҽ���Ԫ��dataΪe

Status traverse_list(LNode* L);//������������,��ӡȫ��

Status traverse_two_way_list(LinkedList_two_way*L);//����˫������,��ӡȫ��

Status search_list(LNode* L, ElemType e);//Ѱ�Ҷ�Ӧ������e�Ľ��

LinkedList reverse_list_recur(LNode* L);//��ת����,�ݹ鷽ʽ

LinkedList reverse_list_interation(LNode* L);//��ת����,������ʽ

Status is_loop_list(LNode* L);//�ж������Ƿ�ɻ�

Status reversr_even_list(LNode* L);//����������ż��������λ��

Status find_mid_node(LNode* L);//Ѱ���м���

Status create_one_way_list(LNode* L);//������������

Status create_two_way_list(LNode_two_way* L);//����˫������

LinkedList create_loop_list(LNode* L);//����ѭ������