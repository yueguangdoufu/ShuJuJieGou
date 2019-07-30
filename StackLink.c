#include"stdio.h"
#include"stdlib.h"

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
#define OVERFLOW 0
#define ERROR 0
#define OK 1
#define TRUE 1
#define FALSE 1

typedef int SElemType;
typedef int Status;

typedef struct{
	SElemType *base;
	SElemType *top;
	int stacksize;
}StackLink;

Status InitStack(StackLink *S)//构造
{
	S->base=(SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if(!S->base)
		exit(OVERFLOW);
	S->top=S->base;
	S->stacksize=STACK_INIT_SIZE;
	return OK;
}

Status DestroyStack(StackLink *S)//销毁
{
	while(S->base!=S->top)
	{
		free(S->base);
		S->base++;
	}
	return OK;
}

Status ClearStack(StackLink *S)//清空
{
	S->top=S->base;
	return OK;
}

Status StackEmpty(StackLink S)//判空
{
	if(S.top==S.base)
		return FALSE;
	return TRUE;
}

int StackLength(StackLink S)//求长
{
	return S.top-S.base;
}

Status GetTop(StackLink S,SElemType *e)//返回栈顶元素
{
	if(S.top==S.base)
		return ERROR;
	*e=*(S.top-1);
	return OK;
}

Status Push(StackLink *S,SElemType e)//压栈
{
	if(S->top-S->base>=S->stacksize)
	{
			S->base=(SElemType *)realloc(S->base,(S->stacksize+STACKINCREMENT) * sizeof(SElemType));
		if(!S->base)
			exit(OVERFLOW);
		S->top=S->base+S->stacksize;
		S->stacksize+=STACKINCREMENT;
	}
	*S->top++=e;
	return OK;
}

Status Pop(StackLink *S,SElemType *e)//出栈
{
	if(S->top==S->base)
		return ERROR;
	*e=*--S->top;
	return OK;
}



void Conversion()//数制转换
{
	int N;
	StackLink S;
	SElemType e;
	InitStack(&S);
	scanf("%d ",&N);
	while(N!=0)
	{
		e=N%8;
		Push(&S,e);
		N=N/8;
	}
	while(!StackEmpty(S))
	{
		Pop(&S,&e);
		printf("%d ",e);
	}
}
int main()
{
	StackLink S;
	if(InitStack(&S)==OK)
		printf("OK!\n");
	Conversion();	
	return 0;
}

