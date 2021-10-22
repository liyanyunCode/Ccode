#include<stdio.h>
#include<string.h>
//杨氏矩阵
//有一个二维数组，数组的每一行从左到右时递增的，每一列从上到下是递增
//在这样一个数组中查找一个数字是否存在
//时间复杂度小于O（n)
//struct Point
//{
//	int x;
//	int y;
//
//};

//struct Point  find(int arr[3][3], int row, int col ,int num)
//{
//	int x = 0;
//	int y = col - 1;
//	struct Point ret = { -1,-1 };
//	while ((x<=2)&&(y>=0))
//	{
//		if (arr[x][y] == num)
//		{
//			ret.x = x;
//			ret.y = y;
//			return ret;
//		}
//		else if (arr[x][y] > num)
//		{
//			y--;
//		}
//		else
//		{
//			x++;
//		}
//	}
//	return ret;
//}
//int main() {
//	int arr[3][3] = { 1,2,3,4,5,6,7,8,9 };
//	//1 2 3
//	//4 5 6
//	//7 8 9 
//
//struct Point	ret=find(arr, 3, 3,7);
//	if ((ret.x != -1)&&(ret.y!=-1))
//	{
//		printf("找到了 %d %d\n",ret.x,ret.y);
//}
//	else 
//	{
//		printf("没找到\n");
//	}
//	return 0;
//}


//另一种方法
void find(int arr[3][3], int* row, int* col, int num)
{
	int x = 0;
	int y = *col - 1;
	while ((x <= *row) && (y >= 0))
	{
		if (arr[x][y] == num)
		{
			*row = x;
			*col = y;
			return;
		}
		else if (arr[x][y] > num)
		{
			y--;
		}
		else
		{
			x++;
		}
	}
	*row = -1;
	*col = -1;

}
int main() {
	int arr[3][3] = { 1,2,3,4,5,6,7,8,9 };
	//1 2 3
	//4 5 6
	//7 8 9 
	int x = 3;
	int y = 3;

     find(arr, &x, &y,-1);
	if ((x != -1) && (y != -1))
	{
		printf("找到了 %d %d\n", x, y);
	}
	else
	{
		printf("没找到\n");
	}
	return 0;
}