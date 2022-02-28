#include <stdio.h>
#include <stdlib.h>
#include "Person.h"
#include "Table2.h"

int MyHashFunc(int k)
{
	return k % 100;
}

int main(void)
{
	Table myTbl;
	Person * np;
	Person * sp;
	Person * rp;

	TBLInit(&myTbl, MyHashFunc);

	int num;
	char name[4];
	char jiyeok[20];
	int n=0;
	while(n!=4)
	{
		printf("Table & Hash stimulater\n1.insert\n2.search\n3.delete\n4.end\nmenu : ");
		scanf("%d",&n);
		switch (n)
		{
			case 1:
			printf("insert num : ");
			scanf("%d",&num);
			printf("insert name : ");
			scanf("%s",name);
			printf("insert where live : ");
			scanf("%s",jiyeok);
			np = MakePersonData(num, name, jiyeok);
			TBLInsert(&myTbl, GetSSN(np), np);
			printf("insert!\n");
			break;

			case 2:
			printf("search num : ");
			scanf("%d",&num);
			sp = TBLSearch(&myTbl, num);
			if(sp != NULL)
				ShowPerInfo(sp);
			else
				printf("NULL\n");
			break;

			case 3:
			printf("Delete num : ");
			scanf("%d",&num);
			rp = TBLDelete(&myTbl, num);
			if(rp != NULL)
				free(rp);
			else
				printf("NULL\n");
			break;
		}
	}
	/*
	// ������ �Է� ///////
	np = MakePersonData(900254, "Lee", "Seoul");
	TBLInsert(&myTbl, GetSSN(np), np);

	np = MakePersonData(900139, "KIM", "Jeju");
	TBLInsert(&myTbl, GetSSN(np), np);

	np = MakePersonData(900827, "HAN", "Kangwon");
	TBLInsert(&myTbl, GetSSN(np), np);

	// ������ Ž�� ///////
	sp = TBLSearch(&myTbl, 900254);
	if(sp != NULL)
		ShowPerInfo(sp);

	sp = TBLSearch(&myTbl, 900139);
	if(sp != NULL)
		ShowPerInfo(sp);

	sp = TBLSearch(&myTbl, 900827);
	if(sp != NULL)
		ShowPerInfo(sp);

	// ������ ���� ///////
	rp = TBLDelete(&myTbl, 900254);
	if(rp != NULL)
		free(rp);

	rp = TBLDelete(&myTbl, 900139);
	if(rp != NULL)
		free(rp);

	rp = TBLDelete(&myTbl, 900827);
	if(rp != NULL)
		free(rp);
*/
	return 0;
}