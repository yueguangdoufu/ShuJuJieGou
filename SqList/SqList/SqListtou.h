#include"stdio.h"
#include"stdlib.h"

#define OVERFLOW 0
#define OK 1
#define ORRER 0
#define TRUE 1
#define FALSE 0
#define ERROR 0
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

typedef int ElemType;
typedef int Status;
typedef struct{
	ElemType *elem;
	int length;
	int listsize;
}SqList;
//构建空链表
Status IniList(SqList *L){
	L->elem=(ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));
	if(!L->elem)
		exit(OVERFLOW);
	L->length=0;
	L->listsize=LIST_INIT_SIZE;
	return OK;
}
//销毁
Status DestroyList(SqList *L){
	if(!L->elem){
		exit(OVERFLOW);
	}
	free(L->elem);
	L->length=0;
	L->listsize=0;
	return OK;
}
//清空
Status ClearList(SqList *L){
	if(!L->elem){
		exit(OVERFLOW);
	}
	L->length=0;
	return OK;
}
//检查是否为空
Status ListEmpty(SqList *L){
	if(!L->elem){
		exit(OVERFLOW);
	}
	return L->length==0?TRUE:FALSE;
}
//长度
int ListLength(SqList *L){
	if(!L->elem){
		exit(OVERFLOW);
	}
	return L->length;
}
//第i个值
Status GetElem(SqList *L,int i,ElemType *e)
{
	if((i<1)||(i>L->length))
		return ERROR;
	*e=L->elem[i-1];
	return OK;
}
//判断位置
int LocateElem(SqList *L,ElemType e,Status(* compare)(ElemType,ElemType)){
	int i=1;
	ElemType *p=L->elem;
	if(!L->elem){
		exit(OVERFLOW);
	}
	while(i<=L->length&&!(* compare)(*p++,e)){
		++i;
	}
	if(i<=L->length)
		return i;
	else return 0;
}
//插入
Status ListInsert(SqList *L,int i,ElemType e){
	int *q;
	int *p;
	ElemType *newbase;
	if(!L->elem){
		exit(OVERFLOW);
	}
	if(i<1||i>L->length+1)
		exit(ERROR);
	if(L->length>=L->listsize){
		newbase = (ElemType *)realloc(L->elem,(L->listsize+LISTINCREMENT)* sizeof(ElemType));
		if(!newbase)
			exit(OVERFLOW);
		L->elem=newbase;
		L->listsize+=LISTINCREMENT;
	}
	q=&(L->elem[i-1]);
	for(p=&(L->elem[L->length-1]);p>=q;--p)
		*(p+1)=*p;
	*q=e;
	++L->length;
	return OK;
}
//删除
Status ListDelete(SqList *L,int i,ElemType *e){
	ElemType *p,*q;
	if((i<1)||(i>L->length))
		return ERROR;
	p=&(L->elem[i-1]);
	*e=*p;
	q=L->elem+L->length-1;
	for(++p;p<=q;++p)
	{
		*(p-1)=*p;
	}
	--L->length;
	return OK;
}
//输入数据
Status CreateList(SqList *L){
	int i=0;
	L->length=0;
	printf("请输入：");
	scanf("%d",&L->elem[i]);
	L->length++;
	while(L->elem[i] !=0)
	{
		i++;
		scanf("%d",&L->elem[i]);
		L->length++;
	}
	return OK;
}
//相等
Status equal(ElemType a,ElemType b)
{
	if(a==b)
		return OK;
	else
		return ERROR;
}
//输出
void PutList(SqList *L){
	int i;
	printf("数据为：");
	for(i=0;i<L->length;i++)
	{
		printf("%d ",L->elem[i]);
	}
	printf("\n");
}