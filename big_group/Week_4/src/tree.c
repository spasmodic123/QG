#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include "b_tree.h"

tree_node InitBRree(tree_node T)//初始化
{	T->data = 5;//初始化先默认根节点的value为9
	T->lchild = NULL;
	T->rchild = NULL;
	return T;
}



// 入栈
void push(StackNode** top, tree_node node) {
	StackNode *newNode = (StackNode*)malloc(sizeof(StackNode));//要入栈,所以创建新的栈结点
	newNode->node = node;//将树的结点赋给新创建的栈结点
	newNode->next = *top;//将新节点的 next 指向栈顶节点
	*top = newNode;//更新栈顶指针,使其指向新的结点
}


tree_node pop(StackNode** top)
{
	tree_node node = (*top)->node; //获取栈顶节点的值，即二叉树节点
	StackNode* temp = *top;// 记录栈顶节点的指针，以便后续释放内存
	*top = (*top)->next;// 更新栈顶指针，使其指向下一个节点
	free(temp);
	return node;// 返回二叉树节点,用于后续打印
}



int isEmpty(StackNode* top) {
	return top == NULL;//如果为空,返回1;否则返回0
}


int insert_node(tree_node T)//插入结点
{
	system("cls");
	printf("\t\t\t\t\t\t\033[33m插入树结点功能 \033[0m\n\n");
	printf("  ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
	char c; int num;
	while (1) {
		tree_node t_tmp = (tree_node)malloc(sizeof(BTree));
		tree_node t_new = (tree_node)malloc(sizeof(BTree));
		t_tmp = T;
		printf("请输入添加的value(输入0添加结束):");
		int ret = scanf("%d", &num);//判断非法输入
		if (ret < 1) {
			while ((c = getchar()) != EOF && c != '\n');
			printf("输入非法!!!请重新输入   \033[31m应该输入一个整数 \033[0m\n");
		}
		if (num == 0) {
			printf("\n添加成功!");
			return OK;
		}
		while(ret==1){//不断查找,小于就找左孩子,大于就找右孩子
			if (num == t_tmp->data) {
				printf("\n添加失败!该数字已存在!\n"); break;
			}
			if (num > t_tmp->data) {
				if (t_tmp->rchild == NULL) {//如果下一个就是null结点,停止查找,插入新节点
					t_new->data = num;
					t_tmp->rchild = t_new;
					t_new->lchild = NULL; t_new->rchild = NULL;//幅上null值
					break;
				}
				t_tmp = t_tmp->rchild;
			}
			else if (num < t_tmp->data) {
				if (t_tmp->lchild == NULL) {//如果下一个就是null结点,停止查找,插入新节点
					t_new->data = num;
					t_tmp->lchild = t_new;
					t_new->lchild = NULL; t_new->rchild = NULL;//幅上null值
					break;
				}
				t_tmp = t_tmp->lchild;
			}
		}
	}
}


int pre_order(tree_node T)//先序遍历,递归
{
	if (!T) {
		return;
	}
	printf("%d ", T->data);
	pre_order(T->lchild);
	pre_order(T->rchild);
}


int mid_order(tree_node T)//中序遍历,递归
{
	if (!T) {
		return;
	}
	mid_order(T->lchild);
	printf("%d ", T->data);
	mid_order(T->rchild);
}


int post_order(tree_node T)//后序遍历,递归
{
	if (!T) {
		return;
	}
	post_order(T->lchild);
	post_order(T->rchild);
	printf("%d ", T->data);
}



int ppre_order_iteration(tree_node T)//迭代遍历,先序
{
	if (T == NULL) return;
	StackNode* stack = NULL;//先创建新的栈对象
	push(&stack, T);
	while (!isEmpty(stack)) {
		tree_node node = pop(&stack);
		printf("%d ", node->data);
		if (node->rchild) push(&stack, node->rchild);
		if (node->lchild) push(&stack, node->lchild);
	}
}



int mid_order_iteration(tree_node T)//迭代遍历,中序
{
	if (T == NULL) return;
	StackNode* stack = NULL;// 创建一个栈用于保存节点
	tree_node node = T; //node接受根节点,从根节点开始遍历
	while (!isEmpty(stack) || node) {
		if (node) {
			push(&stack, node);
			node = node->lchild;//先遍历左边
		}
		else {
			node = pop(&stack);
			printf("%d ", node->data);
			node = node->rchild;//如果左边遍历完,就轮到右边,如果该节点为null,上文node=pop(&stack) 语句可以将node结点回溯到上一个结点
		}
	}
}



int post_order_iteration(tree_node T)//迭代遍历,后序
{
	if (T == NULL) return;
	StackNode* stack1 = NULL;
	StackNode* stack2 = NULL;
	push(&stack1, T);// 将根节点压入栈1中
	while (!isEmpty(stack1)) {
		tree_node node = pop(&stack1);// 弹出栈1的栈顶节点
		push(&stack2, node);// 将弹出的节点压入栈2中
		if (node->lchild) push(&stack1, node->lchild); // 如果弹出的节点有左子树，则将其左子树压入栈1中
		if (node->rchild) push(&stack1, node->rchild);// 如果弹出的节点有右子树，则将其右子树压入栈1中
	}
	while (!isEmpty(stack2)) {
		tree_node node = pop(&stack2);// 弹出栈2的栈顶节点
		printf("%d ", node->data);//输出
	}
}



void initQueue(Queue* q) {//初始化链队
	q->head = q->tail = NULL;
}



void enqueue(Queue* q, tree_node node)//入队
{
	QueueNode* new_node = (QueueNode*)malloc(sizeof(QueueNode));
	new_node->node = node;
	new_node->next = NULL;

	if (q->head == NULL) {
		q->head = q->tail = new_node;
	}
	else {
		q->tail->next = new_node;
		q->tail = new_node;
	}
}



tree_node dequeue(Queue* q)//出队
{
	if (q->head == NULL) {
		return NULL;
	}
	else {
		tree_node node = q->head->node;
		QueueNode* temp = q->head;

		q->head = q->head->next;

		if (q->head == NULL) {
			q->tail = NULL;
		}

		free(temp);
		return node;
	}
}



int level_order(tree_node T)//层次遍历
{
	if (T == NULL) {
		return;
	}

	struct Queue q;
	initQueue(&q);

	enqueue(&q,T);

	while (q.head != NULL) {
		tree_node node = dequeue(&q);
		printf("%d ", node->data);

		if (node->lchild) {
			enqueue(&q, node->lchild);
		}

		if (node->rchild) {
			enqueue(&q, node->rchild);
		}
	}
}



tree_node find_value(tree_node T)
{
	char c; int num;
	while (1) {
		printf("请输入想要查找的值(输入0退出程序):");
		int ret = scanf("%d", &num);//判断非法输入
		if (ret < 1) {
			while ((c = getchar()) != EOF && c != '\n');
			printf("输入非法!!!请重新输入   \033[31m应该输入一个整数 \033[0m\n");
		}
		if (num == 0)exit;
		tree_node t_tmp = (tree_node)malloc(sizeof(BTree));
		t_tmp = T;
		while (1){
			if (t_tmp == NULL) {
				return NULL;//不存在返回null
			}
			if (num > t_tmp->data) {
				t_tmp = t_tmp->rchild;
			}
			else if (num < t_tmp->data) {
				t_tmp = t_tmp->lchild;
			}
			else if(num==t_tmp->data) {
				return t_tmp;
			}
		}
	}
}



tree_node delete_node(tree_node T)
{
	tree_node t_tmp = (tree_node)malloc(sizeof(BTree));
	char c; int num;
	while (1) {
		printf("请输入想要删除的值(输入0返回主菜单):");
		int ret = scanf("%d", &num);//判断非法输入
		if (ret < 1) {
			while ((c = getchar()) != EOF && c != '\n');
			printf("输入非法!!!请重新输入   \033[31m应该输入一个整数 \033[0m\n");
		}
		if (num == 0)return 0;
	}
	t_tmp = find_value(T);//看要删除的值是否存在
	if (t_tmp == NULL) {//不存在删除的值
		return NULL;
	}
	else {
		if (t_tmp->lchild == NULL && t_tmp->rchild == NULL) {//删除的是尾结点
			free(t_tmp); t_tmp = NULL;
			return T;
		}
		else if (t_tmp->lchild == NULL && t_tmp->rchild != NULL) {
			return 0;
		}
	}
}