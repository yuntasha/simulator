#include <stdio.h>
#include "BinaryTree3.h"	// Ʈ���� ������ Ȯ���ϱ� ���ؼ�
#include "BinarySearchTree3.h"

int main(void)
{
	BTreeNode * avlRoot;
	BTreeNode * crNode;		// current node
	BSTMakeAndInit(&avlRoot);

	int n, i,data,seln;
	while(1)
	{
		printf("\n----------------------\n");
		printf("AVL tree stimulater\n1.insert\n2.delete\n3.looking tree\n4.end\n");
		printf("----------------------\n");
		printf("menu : ");
		scanf("%d",&n);
		if(n==1)
		{
			printf("insert data : ");
			scanf("%d",&data);
			BSTInsert(&avlRoot, data);
			printf("insert!\n");
		}
		else if(n==2)
		{
			if(crNode==NULL)
			{
				printf("Root Node is NULL.\n");
				continue;
			}
			printf("delete data : ");
			scanf("%d",&data);
			BSTRemove(&avlRoot, data);
			printf("%d is delete.\n");
		}
		else if(n==3)
		{
			crNode=avlRoot;
			if(crNode==NULL)
			{
				printf("Root Node is NULL.\n");
				continue;
			}
			printf("Root Node data is %d\n",GetData(crNode));
			while(1)
			{
				printf("1 : left\n2 : right\n3 : end\nmenu : ");
				scanf("%d",&seln);
				if(seln==1)
				{
					crNode = GetLeftSubTree(crNode);
					if(crNode==NULL)
					{
						printf("NULL\n");
						break;
					}
					printf("left node is %d.\n",GetData(crNode));	
				}
				else if(seln==2)
				{
					crNode = GetRightSubTree(crNode);
					if(crNode==NULL)
					{
						printf("NULL\n");
						break;
					}
					printf("right node is %d\n",GetData(crNode));	
				}
				else if(seln==3)
					break;
			}
		}
		else if(n==4)
		{
			break;
		}

		
	}
	return 0;
}