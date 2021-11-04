#include<iostream>
#include<string>
using namespace std;
//饮品制作 煮水 冲泡 倒入杯中 加入佐料
//利用多态实现本案例，提供抽象制作饮品基类，提供子类制作咖啡和茶叶
//多态的案列2 在父类中不屑任何实现，在子类中重写具体的实现
//通过不同的函数调用，走不同的路线
class AbstractDrink
{
public:
	//煮水纯虚函数
	virtual void Boil() = 0;
	//冲泡
	virtual void  Brew() = 0;

	//倒入杯中
	virtual void PourInCup() = 0;

	//加入辅助的错料
	virtual void Putst() = 0;

	void makedrink()
	{
		Boil();
		Brew();
		PourInCup();
		Putst();

	}
};
class Coffee :public AbstractDrink
{
public:
	//具体实现
	//煮水
	virtual void Boil()
	{
		cout << "煮水" << endl;

	}
	//冲泡
	virtual void  Brew()
	{
		cout << "冲泡咖啡" << endl;

	}

	//倒入杯中
	virtual void PourInCup()
	{
		cout << "倒入杯中" << endl;

	}

	//加入辅助的错料
	virtual void Putst()
	{
		cout << "加入牛奶和糖" << endl;

	}
};
class Tea :public AbstractDrink
{
public:
	//具体实现
	//煮水
	virtual void Boil()
	{
		cout << "煮开水" << endl;

	}
	//冲泡
	virtual void  Brew()
	{
		cout << "冲泡茶叶" << endl;

	}

	//倒入杯中
	virtual void PourInCup()
	{
		cout << "倒入杯中" << endl;

	}

	//加入辅助的错料
	virtual void Putst()
	{
		cout << "加入柠檬" << endl;

	}
};
//制作函数
void dowork(AbstractDrink* a)
{
	a->makedrink();
	delete a;//释放空间堆区释放掉
}
void test01()
{
	//制作咖啡
	dowork(new Coffee);
	dowork(new Tea);
}
int main()
{
	test01();
	system("pause");
		return 0;
}