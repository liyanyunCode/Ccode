#include<stdio.h>
void ShellSort(int* a, int n)
{
	int gap = n;

	while (gap > 1)
	{
		//gap = gap / 2;  // logN
		gap = gap / 3 + 1; // log3N 以3为底数的对数
		// gap > 1时都是预排序  接近有序
		// gap == 1时就是直接插入排序 有序

		// gap很大时，下面预排序时间复杂度O(N)
		// gap很小时，数组已经很接近有序了，这时差不多也是(N)

		// 把间隔为gap的多组数据同时排
		for (int i = 0; i < n - gap; ++i)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (a[end] > tmp)
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = tmp;
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

//9 1 2 5 7 4 8 6 3 5
void TestShellSort()
{
	int a[] = { 9 ,1, 2, 5, 7, 4, 8 ,6, 3, 5 };
	ShellSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

int main()
{
	TestShellSort();
	return  0;
}