#include<iostream>
#include<string>
using namespace std;
//ģ��
//�������κ���
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


//ģ��ʵ��
//ģ�����Ҫȷ����T���������ͣ��ſ���ʹ��typenameҲ���Ի���class
template<typename T>//����һ��ģ�壬���߱���������Ĵ����е�T��Ҫ����T��һ��ͨ�õ���������
void mySwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

template<typename T>//����ȷ����T���������ͣ��ſ���ʹ��
void func()
{
	cout << "func ������ʹ��" << endl;

}
void test02()
{
	//func();//����û����ʾT������
	func<int>();//��ȷ
}
void tes01()
{
	int a = 10;
	int b = 10;
	char c = 'c';
	//swap(a, b);
	//�Զ������Ƶ��������Ƶ���һ�µ��������Ͳſ���
	mySwap(a, b);
//	mySwap(a, c);//����
	//��ʾָ������
	mySwap<int>(a, b);
	cout << "a��ֵ" << a << endl;
	cout << "b��ֵ" << b << endl;

}

//int main()
//{
//	test01();
//	test02();
//
//	system("pause");
//	return 0;
//}