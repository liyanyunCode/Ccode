//写一个函数返回参数二进制中1的个数
#include<stdio.h>
#include<string.h>
//int main()
//{
//	int num = 15;
//	int count = 0;
//	//1111
//	//111
//	//11
//	//1
//	while (num)
//	{
//		if (num % 2 == 1)
//			count++;
//		num = num / 2;
//	}
//	printf("%d\n", count);
//}
//改进版本，解决负数
int main()
{
	int num = 15;
	int count = 0;
	int i = 0;
	/*for (i = 0; i < 32; i++)
	{
		if (((num >> i) & 1) == 1)
		{
			count++;
		}
		printf("%d\n", count);
	}*/
	//15
	//1111  num
	//1110  num-1
	//1110  前两个与一下赋给num
	//1101  num-1
	//1100  num与
	//1011  num-1
	//1000 num与
	//0111 num-1
	//0000 num与

	while (num)
	{
		num = num & (num - 1);
		count++;
    }
	printf("%d\n", count);

}

//写一个数判断它是二的几次方，思想方法同上
