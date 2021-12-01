#include<stdio.h>
void Swap(int* a1, int* a2)
{
	int temp = *a1;
	*a1 = *a2;
	*a2 = temp;
}
void BubbleSort(int* a,int n)
{
	int i = 0;
	int j = 0;
	for (j = 0; j < n-1; j++)
	{
		for (i = 0; i < n-j-1; i++)
		{
			if (a[i] > a[i + 1])
			{
				Swap(&a[i], &a[i + 1]);
			}
		}
	}

}
void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
void TestBubbleSort()
{
	int a[] = { 9, 3, 5, 2, 7, 8, 6, -1, 9, 4, 0 };
	BubbleSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}
int main()
{
	TestBubbleSort();
	return 0;
}