#include <stdio.h>
#include <stdlib.h>
#include "ListBaseStack.h"

void StackInit(Stack * pstack) //스택의 초기화
{
	pstack->head = NULL;
}

int SIsEmpty(Stack * pstack) //스택이 비었는지 확인
{
	if(pstack->head == NULL) //연결리스트의 머리가 가리키는 것이 없을 시 비었다고 확인
		return TRUE;
	else
		return FALSE;
}

void SPush(Stack * pstack, Data data) //스택에 데이터 넣기
{
	Node * newNode = (Node*)malloc(sizeof(Node)); //노드 작성

	newNode->data = data; //데이터 넣기
	newNode->next = pstack->head; 

	pstack->head = newNode;
}

Data SPop(Stack * pstack) //스택에 데이터 꺼내기
{
	Data rdata;
	Node * rnode;

	if(SIsEmpty(pstack)) { //스택이 비었을 시 오류
		printf("Stack Memory Error!");
		exit(-1);
	}

	rdata = pstack->head->data;
	rnode = pstack->head;

	pstack->head = pstack->head->next;
	free(rnode);

	return rdata;
}

Data SPeek(Stack * pstack) //스택의 데이터 중 마지막 데이터 확인
{
	if(SIsEmpty(pstack)) { //스택이 비었을 시 오류
		printf("Stack Memory Error!");
		exit(-1);
	}

	return pstack->head->data;
}