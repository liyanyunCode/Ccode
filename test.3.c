//��������ʹ����ȫ��λ��ż��ǰ��
//��Ŀ  ����һ���������飬ʵ��һ��������
// �����������������ֵ�˳��ʹ����������������λ�������ǰ�벿��
//����ż��λ������ĺ�벿��

#include<stdio.h>
#include<string.h>
void swap(int arr[], int s)
{
	int left = 0;
	int right = s - 1;
	int temp = 0;
	while(left < right)
	{
		
		while ((arr[left] % 2 == 1)&&(left<right))
		{
			left++;

		}
		while ((arr[right] % 2 == 0) && (left < right))
		{
			right--;
		}
		temp = arr[left];
		arr[left] = arr[right];
		arr[right] = temp;
	}
}
int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	swap(arr,sz);
	return 0;

}
