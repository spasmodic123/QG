#define  _CRT_SECURE_NO_WARNINGS 1
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

#define MAXSTACK 100//栈容量

typedef char StackElemType; //栈数据类型
typedef int Status;

typedef struct __SqStack //顺序栈，最常用
{
	StackElemType* base;
	StackElemType* top;
	int stacksize;
} SqStack;


typedef struct _______SqStack //顺序栈，最常用,第二个栈存放运算的数字,指针类型变为double
{
	double* base;
	double* top;
	int stacksize;
} SqStack_double;


Status InitStack(SqStack* S);
Status Push(SqStack* S, StackElemType e);//字符的入栈
Status Push_number(SqStack_double* S, double e);//数字的入栈
StackElemType Pop(SqStack* S);//字符的出栈
double Pop_number(SqStack_double* S);//数字的出栈
StackElemType GetTop(SqStack* S);
Status IsEmpty(SqStack* S);
int is_illegal(char ch);//判断输入是否非法
int big_or_small(char a, char b);//判断该运算符是大于栈顶元素还是小于
double trans_char_to_double(char x);//定义一个将字符转化为数字的函数
