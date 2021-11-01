#define  _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

//题目说明：第一行输入一个整数N
//第二行输入N个升序排列的整数，输入用空格分开
//第三行输入想要进行插入的一个整数

//输出描述  输出N+1个有序排列的数
int main()
{
	int n = 0;
	int arr[51] = { 0 };
	int m = 0;
	scanf("%d", &n);
	int i = 0;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);

	}
	scanf("%d", &m);

	for (i = n - 1; i >= 0; i--)
	{
		if (arr[i] > m)
		{
			arr[i + 1] = arr[i];

		}
		else
		{
			arr[i + 1] = m;
			break;
		}
	}
	if (i < 0)
	{
		arr[0] = m;
	}
	for (i = 0; i < n + 1; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;


}

