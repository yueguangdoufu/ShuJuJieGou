#include"stdio.h"
#include"stdlib.h"

#define MAXQSIZE 100
#define OK 1
#define ERROR 0
#define FALSE 0
#define TRUE 1
#define OVERFLOW 0

typedef int QElemType;
typedef int Status;
typedef struct{
	QElemType *base;
	int front;
	int length;
	int rear;
}SqQueue;

//	创建
Status InitQueue(SqQueue *Q){
	Q->base = (QElemType *)malloc(MAXQSIZE *sizeof(QElemType));
	if(!Q->base)
		exit(OVERFLOW);
	Q->front = Q->rear = 0;
	Q->length = 0;
	return OK;
}

//	长度
int QueueLength(SqQueue Q){
	return Q.length;
}

//	插入
Status EnQueue (SqQueue *Q,QElemType e){
	if((Q->rear +1) % MAXQSIZE == Q->front)
		return ERROR;
	Q->base[Q->rear] = e;
	Q->rear = (Q->rear + 1)%MAXQSIZE;
	Q->length++;
	return OK;
}

//	删除队头
Status DeQueue(SqQueue *Q,QElemType *e){
	if(Q->front == Q->rear)
		return ERROR;
	*e = Q->base[Q->front];
	Q->front = (Q->front + 1) % MAXQSIZE;
	Q->length--;
	return OK;
}

// 清空
Status ClearQueue(SqQueue *Q){
	Q->rear = Q->front;
	Q->length = 0;
	return OK;
}

// 判空
Status QueueEmpty(SqQueue Q){
	if(Q.length == 0)
		return TRUE;
	else
		return FALSE;
}

//	返回队头
Status GetHead(SqQueue Q,QElemType *e){
	*e = Q.base[Q.front];
	Q.front = Q.front + 1;
	Q.length--;
	return OK;

}