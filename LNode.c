#include"stdio.h"
#include"stdlib.h"

#define OK 1
#define ERROR 0

typedef int Status;
typedef int ElemType;

typedef struct LNode
{
	ElemType data;
	struct LNode *next;
}LNode, *LinkList;

Status CreateList(LinkList *L)
{
	LinkList head;
	head= (LinkList)malloc(sizeof(LNode));
	head->next=NULL;
	*L=head;
	//*L=(LinkList)malloc(sizeof(LNode));
	//(*L)->next=NULL;
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

Status ListDelete(LinkList *L,int i,ElemType *e)
{
	int j=0;
	LinkList p,q;
	p=*L;
	while(p->next)
	{
		if(j==i-1)
		{
			q=p->next;
			p->next=q->next;
			*e=q->data;
			free(q);
			return OK;
		}
		p=p->next;
		j++;
	}
	return ERROR;
}

Status InsertList(LinkList *L,int i,ElemType e)
{
	LinkList p;
	LinkList q;
	int j=0;
	q=(LinkList)malloc(sizeof(LNode));
	q->data=e;
	p=*L;
	if(i<=j)
		return ERROR;
	while(p)
	{
		if(i-1==j)
		{
			q->next=p->next;
			p->next=q;	
		}
		j++;
		p=p->next;
	}
	return OK;
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

/*Status ClearLink(LinkList *L)
{
	LinkLIst p;
	while(p)
	{
		p=L->next;
	}

}*/

void LinkPrint(LinkList L)
{
	LinkList p;
	p=L;
	while(p->next)
	{
		printf("%d ",p->next->data);
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
        printf("%d \n",e );
    else
        printf("下标不存在！");
	if(ListDelete(&L,0,&e)==OK)
		printf("%d \n",e);
	LinkPrint(L);
	InsertList(&L,5,6);
	LinkPrint(L);
}