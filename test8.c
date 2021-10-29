//输入描述
//两行，第一行输入一个整数，表示n个学生，第二行输入学生的成绩
//输出描述
//一行，输出成绩最高的五个，用空格分开
#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int n = 0;
	int arr[40] = { 0 };
	scanf("%d", &n);
	int i = 0;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);


	}
	for (i = 0; i < n - 1; i++)
	{
		int j = 0;
		for (j = 0; j < n - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;

			}
		}
	}
	for (i = n - 1; i >= n - 5; i--)
	{
		printf("%d ", arr[i]);
	}
	return 0;

}