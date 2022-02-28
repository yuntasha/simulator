#include <stdio.h>
#include <stdlib.h>
#include "ListBaseQueue.h"

void QueueInit(Queue * pq) //큐의 초기화
{
	pq->front = NULL;
	pq->rear = NULL;
}

int QIsEmpty(Queue * pq) //큐가 비었는지 확인
{
	if(pq->front == NULL) //머리가 비면 큐가 빈것
		return TRUE;
	else
		return FALSE;
}

void Enqueue(Queue * pq, Data data) //데이터 넣기
{
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->next = NULL; //새로운 노드가 가리키는 방향은 NULL이다 (매우중요)
	newNode->data = data;

	if(QIsEmpty(pq)) //큐가 비었다면 머리와 꼬리가 데이터를 가리키도록
	{
		pq->front = newNode;
		pq->rear = newNode;
	}
	else
	{
		pq->rear->next = newNode; //큐가 비지 않았다면 꼬리뒤에 새로운 노드를 붙여줌
		pq->rear = newNode;
	}
}

Data Dequeue(Queue * pq) //데이터 꺼낼 때
{
	Node * delNode;
	Data retData;

	if(QIsEmpty(pq))
	{
		printf("Queue Memory Error!");
		exit(-1);
	}

	delNode = pq->front; //제일 앞 노드를 가져옴
	retData = delNode->data; //데이터를 꺼냄
	pq->front = pq->front->next; //머리가 가리키는 데이터를 머리 다음으로 설정 (즉 다음이 없다면 NULL이나옴)

	free(delNode);
	return retData;
}

Data QPeek(Queue * pq) //데이터 확인
{
	if(QIsEmpty(pq))
	{
		printf("Queue Memory Error!");
		exit(-1);
	}

	return pq->front->data;
}