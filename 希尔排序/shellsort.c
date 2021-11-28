#include<stdio.h>
void ShellSort(int* a, int n)
{
	int gap = n;

	while (gap > 1)
	{
		//gap = gap / 2;  // logN
		gap = gap / 3 + 1; // log3N ��3Ϊ�����Ķ���
		// gap > 1ʱ����Ԥ����  �ӽ�����
		// gap == 1ʱ����ֱ�Ӳ������� ����

		// gap�ܴ�ʱ������Ԥ����ʱ�临�Ӷ�O(N)
		// gap��Сʱ�������Ѿ��ܽӽ������ˣ���ʱ���Ҳ��(N)

		// �Ѽ��Ϊgap�Ķ�������ͬʱ��
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