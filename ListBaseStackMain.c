#include <stdio.h>
#include "ListBaseStack.h"

void StackInit(Stack * pstack); //스택의 초기화
int SIsEmpty(Stack * pstack); //스택이 비었는지 확인

void SPush(Stack * pstack, Data data); //스택에 데이터 넣기
Data SPop(Stack * pstack); //스택에 데이터 꺼내기
Data SPeek(Stack * pstack); //스택의 데이터 중 마지막 데이터 확인


int main()
{
    
    Stack stack;
    StackInit(&stack);
    int menu,num;
    printf(" 0 : data push\n 1 : data pop\n 2 : data peek\n 3 : end\n");
    while(1)
    {
        printf("menu : ");
        scanf("%d",&menu);
        if(menu==0)
        {
            printf("data push : ");
            scanf("%d",&num);
            SPush(&stack,num);
        }
        else if(menu==1)
        {
            if(SIsEmpty(&stack))
            {
                printf("Stack is empty\n");
                continue;
            }
            printf("data pop %d\n",SPop(&stack));
        }
        else if(menu==2)
        {
            if(SIsEmpty(&stack))
            {
                printf("Stack is empty\n");
                continue;
            }
            printf("data peek %d\n",SPeek(&stack));
        }
        else
        {
            break;
        }
    }
    return 0;
}