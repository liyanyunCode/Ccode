//�����������ϲ������������飬�úϳɵ�����Ҳ�������
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int main()
{
	int i = 0;
	int j = 0;
	int k = 0;
	int n1;
	int n2;
	int arr1[100];
	int arr2[100];
	int arr3[200];
	printf("�������һ�����������\n");
	scanf("%d", &n1);

	for (i = 0; i < n1; i++)
	{
		scanf("%d", &arr1[i]);

	}
	printf("������ڶ�������ĳ��ȣ�\n");
	scanf("%d", &n2);
	for (i = 0; i < n2; i++)
	{
		scanf("%d", &arr2[i]);
	}

	//������кϲ��������
	while (i<n1&&j<n2)
	{
		if (arr1[i++] < arr2[j++])
		{
			arr3[k++] = arr1[i];
		}
		else
		{
			arr3[k++] = arr2[j];
		}
	}
	if (i == n1)
	{
		for (; j < n2; j++)
		{
			arr3[k++] = arr2[j];
		}
	}
	else
	{
		for (; i < n1; i++)
		{
			arr3[k++] = arr1[i];
		}
	}
	for (i = 0; i < k; i++)
	{
		printf("%d", arr3[i]);
	}
	return 0;
}