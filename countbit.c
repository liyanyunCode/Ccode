//дһ���������ز�����������1�ĸ���
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
//�Ľ��汾���������
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
	//1110  ǰ������һ�¸���num
	//1101  num-1
	//1100  num��
	//1011  num-1
	//1000 num��
	//0111 num-1
	//0000 num��

	while (num)
	{
		num = num & (num - 1);
		count++;
    }
	printf("%d\n", count);

}

//дһ�����ж����Ƕ��ļ��η���˼�뷽��ͬ��
