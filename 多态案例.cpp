#include<iostream>
using namespace std;
#include<string>
//�ֱ�����ͨд���Ͷ�̬����ʵ�ּ�����


//��ͨд��
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




//�������չ�µĹ��ܣ���Ҫ�޸�Դ��
//�ڿ����У��ᳫ ����ԭ��
//����չ���п��ţ����޸Ľ��йر�
//���ö�̬ʵ�ּ�����

//ʵ�ּ������ĳ�����
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
//��Ƽӷ���������
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
	//��̬��ʹ������
	//����ָ���������ָ������Ķ���
	//�ӷ�����
	AbstractCalculator * a = new addCalculator;
	a->num1 = 10;
	a->num2 = 10;
	cout << a->num1 << "+" << a->num2 << "=" << a->getresult() << endl;
	//�����ǵ�ɾ��
	delete a;
	//����������
	a = new subCalculator;
	a->num1 = 10;
	a->num2 = 10;
	cout << a->num1 << "-" << a->num2 << "=" << a->getresult() << endl;
	delete a;
	//�˷����㣬һ���ĵ���
	//����֪����̬�ĺô�
	//��֯�ṹ����
	//�ɶ���ǿ
	//���ں��ڵĻ���ǰ�ڵ���չ�Լ�ά���ԱȽϸߣ������޸�Դ�룬�ȽϷ��㣬��ʱ��ֻ��Ҫ׷�ӾͿ���


}
int main()
{
	test01();
	test02();
	system("pause");
}