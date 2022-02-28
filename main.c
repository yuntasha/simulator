#include <stdio.h>
#include <stdlib.h>

/*
AVLTreeMain
BinarySearchTreeMain
ChainedTableMain
HeapMain
ListBaseQueue
ListBaseStackMain
*/
int main()
{
	int i;
	printf("menu\n");
	printf("1.AVLTree\n");
	printf("2.BinarySearchTree\n");
	printf("3.ChainedTable\n");
	printf("4.Heap\n");
	printf("5.ListBaseQueue\n");
	printf("6.ListBaseStack\n");
	printf("7.End\n");
	printf("select menu : ");
	scanf("%d",&i);
	while(i!=7)
	{
		if(i==1)
		{
			system("AVLTreeMain.exe");
			system("pause");
		}
		else if(i==2)
		{
			system("BinarySearchTreeMain.exe");
			system("pause");
		}
		else if(i==3)
		{
			system("ChainedTableMain.exe");
			system("pause");
		}
		else if(i==4)
		{
			system("HeapMain.exe");
			system("pause");
		}
		else if(i==5)
		{
			system("ListBaseQueue.exe");
			system("pause");
		}
		else if(i==6)
		{
			system("ListBaseStackMain.exe");
			system("pause");
		}
		printf("menu\n");
		printf("1.AVLTree\n");
		printf("2.BinarySearchTree\n");
		printf("3.ChainedTable\n");
		printf("4.Heap\n");
		printf("5.ListBaseQueue\n");
		printf("6.ListBaseStack\n");
		printf("7.End\n");
		printf("select menu : ");
		scanf("%d",&i);		
	}
	
	return 0;
}