#include <stdio.h>
#include "ListBaseQueue.h"

int main()
{
    Queue q;
	QueueInit(&q);


    int menu,num;
    printf(" 0 : Enqueue\n 1 : Dequeue\n 2 : QPeek\n 3 : end\n");


    while(1)
    {
        printf("menu : ");
        scanf("%d",&menu);
        if(menu==0)
        {
            printf("Enqueue : ");
            scanf("%d",&num);
            Enqueue(&q,num);
        }
        else if(menu==1)
        {
            if(QIsEmpty(&q))
            {
                printf("Queue is empty\n");
                continue;
            }
            printf("Dequeue %d\n",Dequeue(&q));
        }
        else if(menu==2)
        {
            if(QIsEmpty(&q))
            {
                printf("Queue is empty\n");
                continue;
            }
            printf("QPeek %d\n",QPeek(&q));
        }
        else
        {
            break;
        }
    }
    return 0;
}