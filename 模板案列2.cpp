#include<iostream>
#include<string>
using namespace std;
//�������������ú���ģ���װһ������ĺ��������ԶԲ�ͬ���������������������
//�������Ӵ�С�������㷨Ϊѡ������
//�ֱ�����char�����int������в���
template<typename T>//����һ��ģ�壬���߱���������Ĵ����е�T��Ҫ����T��һ��ͨ�õ���������
void mySwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}


template<typename T>
void mySort(T arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		int max = i;
		for (int j = i + 1; j < len; j++)
		{
			if (arr[max] < arr[j])
			{
				max = j;
			}
		}
		if (max != i)
		{
			mySwap(arr[max], arr[i]);
		}
	}
}

template<typename T>
void printhanshu(T arr[],int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << "  ";

}
	cout << endl;

}
void test01()
{
	char charArry[] = "bagfdhdj";
	int num = sizeof(charArry) / sizeof(char);
	mySort(charArry, num);
	printhanshu(charArry, num);
}
//int main()
//{
//	system("pause");
//	return 0;
//
//}