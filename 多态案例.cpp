#include<iostream>
using namespace std;
#include<string>
//分别用普通写法和多态技术实现计算器


//普通写法
class Calculator
{
public:
	int num1;
	int num2;
	int getresult(string oper)
	{
		if (oper == "+")
		{
			return num1 + num2;
	
		}
		else if (oper == "-")
		{
			return num1 - num2;
		}
		else if (oper == "*")
		{
			return num1 * num2;
		}
	}
};
void test01()
{
	Calculator c;
	c.num1 = 10;
	c.num2 = 10;
	cout << c.num1 << "+" << c.num2 <<"="<< c.getresult("+") << endl;
	cout << c.num1 << "-" << c.num2 << "=" << c.getresult("-") << endl;
	cout << c.num1 << "*" << c.num2 << "=" << c.getresult("*") << endl;

}




//如果想扩展新的功能，需要修改源码
//在开发中，提倡 开闭原则
//对扩展进行开放，对修改进行关闭
//利用多态实现计算器

//实现计算器的抽象类
class AbstractCalculator
{
public:
	int num1;
	int num2;
	virtual int getresult()
	{
		return 0;
	}
};
//设计加法计算器类
class addCalculator :public AbstractCalculator
{
public:
	virtual int getresult()
	{
		return num1+num2;
	}

};
class subCalculator :public AbstractCalculator
{
public:
	virtual int getresult()
	{
		return num1 - num2;
	}

};
class mulCalculator :public AbstractCalculator
{
public:
	virtual int getresult()
	{
		return num1 * num2;
	}

};
void test02()
{
	//多态的使用条件
	//父类指针或是引用指向子类的对象
	//加法运算
	AbstractCalculator * a = new addCalculator;
	a->num1 = 10;
	a->num2 = 10;
	cout << a->num1 << "+" << a->num2 << "=" << a->getresult() << endl;
	//用完后记得删除
	delete a;
	//减法计算器
	a = new subCalculator;
	a->num1 = 10;
	a->num2 = 10;
	cout << a->num1 << "-" << a->num2 << "=" << a->getresult() << endl;
	delete a;
	//乘法运算，一样的道理
	//可以知道多态的好处
	//组织结构清晰
	//可读性强
	//对于后期的或是前期的扩展以及维护性比较高，不用修改源码，比较方便，有时候只需要追加就可以


}
int main()
{
	test01();
	test02();
	system("pause");
}