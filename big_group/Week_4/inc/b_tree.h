#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

#define MAXSTACK 100;

typedef int ElemType;

typedef struct BTree {//树的定义
	ElemType data;
	struct BTree *lchild;
	struct BTree *rchild;
}BTree,*tree_node;
	

typedef struct StackNode {//存放树的结点的地址的栈
	struct TreeNode* node;
	struct StackNode* next;
}StackNode;

typedef struct QueueNode {//链队每一个结点
	struct TreeNode* node;
	struct QueueNode* next;
}QueueNode;

typedef struct Queue {//链队头尾结点
	struct QueueNode* head;
	struct QueueNode* tail;
}Queue;



tree_node InitBRree(tree_node T);//初始化
void initQueue(Queue* q);

void push(StackNode** top, tree_node node);//出栈入栈
tree_node pop(StackNode** top);
int isEmpty(StackNode* top);//判断堆栈是否为空

void enqueue(Queue* q, tree_node node);
tree_node dequeue(Queue* q);

int pre_order(tree_node T);//递归遍历
int mid_order(tree_node T);
int post_order(tree_node T);

int ppre_order_iteration(tree_node T);//迭代遍历
int mid_order_iteration(tree_node T);
int post_order_iteration(tree_node T);

int level_order(tree_node T);//层次遍历

tree_node find_value(tree_node T);//查找
tree_node delete_node(tree_node T);//删除
int insert_node(tree_node T);//插入