//��������
//���У���һ������һ����������ʾn��ѧ�����ڶ�������ѧ���ĳɼ�
//�������
//һ�У�����ɼ���ߵ�������ÿո�ֿ�
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