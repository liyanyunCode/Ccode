#define  _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

//��Ŀ˵������һ������һ������N
//�ڶ�������N���������е������������ÿո�ֿ�
//������������Ҫ���в����һ������

//�������  ���N+1���������е���
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

