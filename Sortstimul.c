#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "UsefulHeap.h"
#include "ListBaseQueue.h"

int PriComp(int n1, int n2)
{
	return n2-n1;
//	return n1-n2;
}

void HeapSort(int arr[], int n, PriorityComp pc)
{
	Heap heap;
	int i;

	HeapInit(&heap, pc);

	// ���� ����� ������ ���� �����Ѵ�.
	for(i=0; i<n; i++)
		HInsert(&heap, arr[i]);

	// ������� �ϳ��� ������ ������ �ϼ��Ѵ�.
	for(i=0; i<n; i++)
		arr[i] = HDelete(&heap);
}

void BubbleSort(int arr[], int n)
{
	int i, j;
	int temp;

	for(i=0; i<n-1; i++)
	{
		for(j=0; j<(n-i)-1; j++)
		{
			if(arr[j] > arr[j+1])
			{
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}

void InserSort(int arr[], int n)
{
	int i, j;
	int insData;

	for(i=1; i<n; i++)
	{
		insData = arr[i];   // ���� ����� insData�� ����

		for(j=i-1; j>=0 ; j--)
		{
			if(arr[j] > insData) 
				arr[j+1] = arr[j];    // �� ��� �� ĭ �ڷ� �б�
			else
				break;   // ���� ��ġ ã������ Ż��!
		}

		arr[j+1] = insData;  // ã�� ��ġ�� ���� ��� ����!
	}
}

void MergeTwoArea(int arr[], int left, int mid, int right)
{
	int fIdx = left;
	int rIdx = mid+1;
	int i;

	int * sortArr = (int*)malloc(sizeof(int)*(right+1));
	int sIdx = left;

	while(fIdx<=mid && rIdx<=right)
	{
		if(arr[fIdx] <= arr[rIdx])
			sortArr[sIdx] = arr[fIdx++];
		else
			sortArr[sIdx] = arr[rIdx++];

		sIdx++;
	}

	if(fIdx > mid)
	{
		for(i=rIdx; i<=right; i++, sIdx++)
			sortArr[sIdx] = arr[i];
	}
	else
	{
		for(i=fIdx; i<=mid; i++, sIdx++)
			sortArr[sIdx] = arr[i];
	}

	for(i=left; i<=right; i++)
		arr[i] = sortArr[i];
	
	free(sortArr);
}

void MergeSort(int arr[], int left, int right)
{
	int mid;

	if(left < right)
	{
		// �߰� ������ ����Ѵ�.
		mid = (left+right) / 2;

		// �ѷ� ������ ������ �����Ѵ�.
		MergeSort(arr, left, mid);
		MergeSort(arr, mid+1, right);

		// ���ĵ� �� �迭�� �����Ѵ�.
		MergeTwoArea(arr, left, mid, right);
	}
}

void Swap(int arr[], int idx1, int idx2)
{
	int temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;
}	


int Partition(int arr[], int left, int right)
{
	int pivot = arr[left];    // �ǹ��� ��ġ�� ���� ����! 
	int low = left+1;
	int high = right;

	while(low <= high)    // �������� ���� ������ �ݺ�
	{	
		while(pivot > arr[low])
			low++;

		while(pivot < arr[high])
			high--;
		
		/*
		while(pivot >= arr[low] && low <= right)
			low++;

		while(pivot <= arr[high] && high >= (left+1))
			high--;
		*/

		if(low <= high)    // �������� ���� ���¶�� Swap ����
			Swap(arr, low, high);    // low�� high�� ����Ű�� ��� ��ȯ
	}

	Swap(arr, left, high);    // �ǹ��� high�� ����Ű�� ��� ��ȯ
	return high;    // �Ű��� �ǹ��� ��ġ ���� ��ȯ
}

void QuickSort(int arr[], int left, int right)
{
	if(left <= right)
	{
		int pivot = Partition(arr, left, right);    // �ѷ� ������ 
		QuickSort(arr, left, pivot-1);    // ���� ������ ����
		QuickSort(arr, pivot+1, right);    // ������ ������ ����
	}
}

#define BUCKET_NUM		10

void RadixSort(int arr[], int num, int maxLen)   // maxLen�� ���� �� �������� ����
{
	Queue buckets[BUCKET_NUM];
	int bi;
	int pos;
	int di;
	int divfac = 1;
	int radix;

	// �� 10���� ��Ŷ �ʱ�ȭ
	for(bi=0; bi<BUCKET_NUM; bi++)
		QueueInit(&buckets[bi]);

	// ���� �� �������� ���̸�ŭ �ݺ�
	for(pos=0; pos<maxLen; pos++)
	{ 
		// ���� ����� ����ŭ �ݺ�
		for(di=0; di<num; di++)
		{
			// N��° �ڸ��� ���� ����
			radix = (arr[di] / divfac) % 10;

			// ������ ���ڸ� �ٰŷ� ������ ��Ŷ�� ����
			Enqueue(&buckets[radix], arr[di]);
		}

		// ��Ŷ ����ŭ �ݺ�
		for(bi=0, di=0; bi<BUCKET_NUM; bi++)
		{
			// ��Ŷ�� ����� �� ������� �� ������ �ٽ� arr�� ����
			while(!QIsEmpty(&buckets[bi]))
				arr[di++] = Dequeue(&buckets[bi]);
		}

		// N��° �ڸ��� ���� ������ ���� �������� ����
		divfac *= 10;
	}	
}

void SelSort(int arr[], int n)
{
	int i, j;
	int maxIdx;
	int temp;

	for(i=0; i<n-1; i++)
	{
		maxIdx = i;    // ���� ������ ���� �ռ��� �������� index

		for(j=i+1; j<n; j++)   // �ּҰ� Ž��
		{
			if(arr[j] < arr[maxIdx])
				maxIdx = j;
		}

		/* ��ȯ */
		temp = arr[i];
		arr[i] = arr[maxIdx];
		arr[maxIdx] = temp;
	}
}


int main()
{
    clock_t start, end;
    int num[100]; //백업 용
    int arr[100]; //배열 돌리는 용
    int i;
    float res; //시간 결과;
    int n; //배열 개수;

    printf("(not over 100)How many array data : \n");
    scanf("%d",&n);
    
    printf("you can write %d number not over 100,000 : ",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&num[i]);
    }


    for(i=0;i<n;i++)
    {
        arr[i]=num[i];
    }
    start = clock();
    BubbleSort(arr, n);
    end = clock();
    res = (float)(end - start)/CLOCKS_PER_SEC;
    
    printf("BubbleSort : %f\n", res);
    printf("start time : %d\n",start);
    printf("end time : %d\n",end);


    for(i=0;i<n;i++)
    {
        arr[i]=num[i];
    }
    start = clock();
    SelSort(arr, n);
    end = clock();
    res = (float)(end - start)/CLOCKS_PER_SEC;

    printf("SelSort : %f\n", res);
    printf("start time : %d\n",start);
    printf("end time : %d\n",end);

    for(i=0;i<n;i++)
    {
        arr[i]=num[i];
    }
    start = clock();
    InserSort(arr, n); 
    end = clock();
    res = (float)(end - start)/CLOCKS_PER_SEC;

    printf("InserSort : %f\n", res);
    printf("start time : %d\n",start);
    printf("end time : %d\n",end);

    
    for(i=0;i<n;i++)
    {
        arr[i]=num[i];
    }
    start = clock();
    MergeSort(arr, 0, n-1);
    end = clock();
    res = (float)(end - start)/CLOCKS_PER_SEC;

    printf("MergeSort : %f\n", res);
    printf("start time : %d\n",start);
    printf("end time : %d\n",end);

    
    for(i=0;i<n;i++)
    {
        arr[i]=num[i];
    }
    start = clock();
    QuickSort(arr, 0, n-1); 
    end = clock();
    res = (float)(end - start)/CLOCKS_PER_SEC;

    printf("QuickSort : %f\n", res);
    printf("start time : %d\n",start);
    printf("end time : %d\n",end);

    
    for(i=0;i<n;i++)
    {
        arr[i]=num[i];
    }
    start = clock();
    HeapSort(arr, n, PriComp); 
    end = clock();
    res = (float)(end - start)/CLOCKS_PER_SEC;

    printf("HeapSort : %f\n", res);
    printf("start time : %d\n",start);
    printf("end time : %d\n",end);

    
    for(i=0;i<n;i++)
    {
        arr[i]=num[i];
    }
    start = clock();
    RadixSort(arr, n, 5); 
    end = clock();
    res = (float)(end - start)/CLOCKS_PER_SEC;

    printf("RadixSort : %f\n", res);
    printf("start time : %d\n",start);
    printf("end time : %d\n",end);

    return 0;
}