#include<iostream>
#include<string>
using namespace std;
//案列描述，利用函数模板封装一个排序的函数，可以对不同的数据类型数组进行排序
//排序规则从大到小，排序算法为选择排序
//分别利用char数组和int数组进行测试
template<typename T>//声明一个模板，告诉编译器后面的代码中的T不要报错，T是一个通用的数据类型
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