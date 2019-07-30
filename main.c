#include"stdio.h"

#define OK 1
#define NULL 0
#define ERROR 0

typedef int Status;
typedef int ElemType;

typedef struct LNode
{
	ElemType data;
	struct Lnode *next;
}LNode, *LinkList;

Status CreateList(LinkList *L)
{
	*L=(LinkList*)malloc(sizeof(LNode));
	(*L)->next=NULL;
	return OK;
}

void CreateList_(LinkList L,int n)
{
	LinkList p;
	LinkList q;
	int i;
	q=L;
	for(i=n;i>0;--i)
	{
		p=(LinkList)malloc(sizeof(LNode));
		scanf("%d",&p->data);
		//p->next=L->next;
		//L->next=p;
		p->next=q->next;
		q->next=p;
		q=p;

	}
}

Status GetElem(LinkList L,int i,ElemType *e)
{
    LinkList p;
    int j;
    p=L->next;
    j=1;
    while(p&&j<i)
    {
        p=p->next;
        ++j;
    }
    if(!p||j>i)
        return ERROR;
    *e=p->data;
    return OK;
}
void LinkPrint(LinkList L)
{
	LinkList p;
	p=L->next;
	while(p)
	{
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}
int main()
{
	LinkList L;
	ElemType e;
	if(CreateList(&L)==OK)
		printf("成功！\n");
	else
		printf("失败！\n");
	printf("请输入数据：");
	CreateList_(L,5);
	LinkPrint(L);
	if(GetElem(L,3,&e)==OK)
        printf("%d ",e );
    else
        printf("下标不存在！");
}
