#define  _CRT_SECURE_NO_WARNINGS 1
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int Status;
typedef int ElemType;

typedef struct LNode {//单向链表
	ElemType data;
	struct LNode* next;
}LNode,*LinkedList;


typedef struct LNode_two_way {//双向链表
	ElemType data;
	struct LNode_two_way* front;
	struct LNode_two_way* next;
}LNode_two_way,*LinkedList_two_way;



//                                声明函数

LinkedList init_link(LNode* L);// 初始化单向链表

LinkedList_two_way init_link_two_way(LNode_two_way* L);//初始化双向链表

Status destroy_list(LNode* L);//销毁链表

Status delete_list(LNode* L,ElemType e);//删除链表中的某一个元素

Status insert_list(LNode* L, int position, ElemType e);//在position后的结点插入结点,且结点的元素data为e

Status traverse_list(LNode* L);//遍历单向链表,打印全部

Status traverse_two_way_list(LinkedList_two_way*L);//遍历双向链表,打印全部

Status search_list(LNode* L, ElemType e);//寻找对应着数据e的结点

LinkedList reverse_list_recur(LNode* L);//反转链表,递归方式

LinkedList reverse_list_interation(LNode* L);//反转链表,迭代方式

Status is_loop_list(LNode* L);//判断链表是否成环

Status reversr_even_list(LNode* L);//链表中奇数偶数结点调换位置

Status find_mid_node(LNode* L);//寻找中间结点

Status create_one_way_list(LNode* L);//创建单向链表

LinkedList_two_way create_two_way_list(LNode_two_way* L);//创建双向链表

LinkedList create_loop_list(LNode* L);//创建循环链表