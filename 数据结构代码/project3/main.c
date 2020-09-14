#define _CRT_SECURE_NO_WARNINGS 1
#include "heap.h"
void main()
{
	int ar[] = { 27,15,19,18,28,34,65,49,25,37 };
	int n = sizeof(ar) / sizeof(ar[0]); //
	Heap minheap;
	HeapInit(&minheap, n);
	for (int i = 0; i < n; ++i)
		MinHeapInsert(&minheap, ar[i]);
	printf("调整为最小堆：");
	HeapPrint(&minheap);
	printf("移除节点的顺序为:");
	while (!HeapEmpty(&minheap))
	{
		printf("%d ", MinHeapRemove(&minheap));
		//HeapPrint(&minheap);
	}
	printf("\n");
	system("pause");
}