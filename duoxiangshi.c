#include"stdio.h"
#include"stdlib.h"

#define OK 1
#define ERROR 0

typedef int Status;
typedef int ElemType;

typedef struct LNode
{
	ElemType data;
	ElemType data1;
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
		scanf("%d %d",&p->data,&p->data1);
		//p->next=L->next;
		//L->next=p;
		p->next=q->next;
		q->next=p;
		q=p;

	}
}

Status AddList(LinkList L,LinkList L1,LinkList *L2)
{
	LinkList q;
	LinkList p;
	LinkList t;
	LinkList t0;
	t0=L2;
	q=L->next;
	p=L1->next;
	while()
	{
		if(q->data1==p->data1)	
		{
			if(q->data+p->data!=0)
			{	
				t=(LinkList)malloc(sizeof(LNode));
				t->data=q->data+p->data;
				t->data1=q->data1;
				t->next=t0->next;
				t0->next=t;
				t0=t;
				p=p->next;
			}
		}
		else
		{	
			t=(LinkList)malloc(sizeof(LNode));
			t->data=q->data;
			t->data1=q->data1;
			t->next=t0->next;
			t0->next=t;
			t0=t;
		}
		t=t->next;
		q=q->next;
	}
}

int main()
{
	LinkList L;
	LinkList L1;
	LinkList L2;
	CreateList(&L2)
	if(CreateList(&L)==OK)
	{	
		if(CreateList(&L1)==OK)
		{
			printf("³É¹¦£¡\n");
			CreateList_(L,5);
			CreateList_(L1,7);
		}
	}
	else
		printf("Ê§°Ü£¡\n");
	
	return 0;
}