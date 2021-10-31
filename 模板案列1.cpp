#include<iostream>
#include<string>
using namespace std;
//模板
//交换整形函数
void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void swapDouble(double &a,double &b)
{
	double temp = a;
	a = b;
	b = temp;
}


//模板实现
//模板必须要确定出T的数据类型，才可以使用typename也可以换成class
template<typename T>//声明一个模板，告诉编译器后面的代码中的T不要报错，T是一个通用的数据类型
void mySwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

template<typename T>//必须确定出T的数据类型，才可以使用
void func()
{
	cout << "func 函数的使用" << endl;

}
void test02()
{
	//func();//错误，没有显示T的类型
	func<int>();//正确
}
void tes01()
{
	int a = 10;
	int b = 10;
	char c = 'c';
	//swap(a, b);
	//自动类型推导，必须推导出一致的数据类型才可以
	mySwap(a, b);
//	mySwap(a, c);//错误
	//显示指定类型
	mySwap<int>(a, b);
	cout << "a的值" << a << endl;
	cout << "b的值" << b << endl;

}

//int main()
//{
//	test01();
//	test02();
//
//	system("pause");
//	return 0;
//}