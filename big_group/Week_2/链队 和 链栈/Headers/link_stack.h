#define  _CRT_SECURE_NO_WARNINGS 1
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int Status;
typedef int ElemType;

typedef struct StackNode { //定义链栈
	ElemType data;
	struct LinkStack* next;
}StackNode, * LinkStack;

Status initLStack(LinkStack S);//初始化栈
Status isEmptyLStack(LinkStack S);//判断栈是否为空
Status getTopLStack(LinkStack S);//得到栈顶元素
LinkStack destroyLStack(LinkStack S);//销毁栈
Status LStackLength(LinkStack S);//检测栈长度
LinkStack pushLStack(LinkStack S);//入栈
LinkStack popLStack(LinkStack S);//出栈

