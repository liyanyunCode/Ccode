//调整数组使奇数全部位于偶数前面
//题目  输入一个整数数组，实现一个函数，
// 来调整该数组中数字的顺序使得数组中所有奇数位于数组的前半部分
//所有偶数位于数组的后半部分

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
