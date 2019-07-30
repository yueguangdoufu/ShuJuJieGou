#include"stdio.h"
#include"stdlib.h"

#define OK 1
#define OVERFLOW 0
#define ERROR 0
#define FALSE 0
#define TRUE 1

typedef int QElemType;
//typedef int QueuePtr;
typedef int Status;
typedef struct QNode {
	QElemType data;
	struct QNode *next;
}QNode, *QueuePtr;

typedef struct {
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;

//	新建
Status InitQueue (LinkQueue *Q){
	Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode));
	if(!Q->front)
		exit(OVERFLOW);
	Q->front->next = NULL;
	return OK;
}

//	销毁
Status DestroyQueue (LinkQueue *Q){
	while (Q->front ){
		Q->rear = Q->front->next;
		free(Q->front );
		Q->front = Q->rear;

	}
	return OK;
}

//	插入
Status EnQueue(LinkQueue *Q,QElemType e){
	QueuePtr p;
	p = (QueuePtr)malloc(sizeof(QNode));
	if(!p)
		exit(OVERFLOW);
	p->data = e;
	p->next = NULL;
	Q->rear->next = p;
	Q->rear = p;
	return OK;
}

//	出队
Status DeQueue(LinkQueue *Q,QElemType *e){
	QueuePtr p;
	if(Q->front == Q->rear){
		return ERROR;
	}
	p = Q->front->next;
	*e = p->data;
	Q->front->next = p->next;
	if(Q->rear == p)
		Q->rear = Q->front;
	free(p);
	return OK;

}

//	清空
Status ClearQueue(LinkQueue *Q){
	QueuePtr p;
	while(Q->front != Q->rear)
	{
		p = Q->front->next;
		Q->front->next = p->next;
		free(p);
	}
	Q->front->next = NULL;
	return OK;
}

//	判空
Status QueueEmpty(LinkQueue Q){
	if(Q.front == Q.rear)
		return TRUE;
	else
		return FALSE;
}

//	队列长度
int QueueLenth(LinkQueue Q){
	return Q.rear - Q.front;
}

//	返回队头
Status GetHead(LinkQueue Q,QElemType *e){
	if(Q.front == Q.rear)
		return ERROR;
	else
		*e = Q.front->next->data;
	return OK;
}

