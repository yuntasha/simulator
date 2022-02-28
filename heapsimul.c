#include <stdio.h>
#include "PriorityQueue.h"

int DataPriorityComp(char ch1, char ch2)
{
	return ch2-ch1;
}

int main(void)
{
	Heap h;
	HeapInit(&h,DataPriorityComp);


    int menu,num;
    printf(" 0 : Insert\n 1 : Delete\n 2 : end\n");


    while(1)
    {
        printf("menu : ");
        scanf("%d",&menu);
        if(menu==0)
        {
            printf("Insert : ");
            scanf("%d",&num);
            HInsert(&h,num);
        }
        else if(menu==1)
        {
            if(HIsEmpty(&h))
            {
                printf("Heap is empty\n");
                continue;
            }
            printf("Delete %d\n",HDelete(&h));
        }
        else
        {
            break;
        }
    }
	return 0;
}
