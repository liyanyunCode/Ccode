#include<iostream>
#include<string>
using namespace std;
//��Ʒ���� ��ˮ ���� ���뱭�� ��������
//���ö�̬ʵ�ֱ��������ṩ����������Ʒ���࣬�ṩ�����������ȺͲ�Ҷ
//��̬�İ���2 �ڸ����в�м�κ�ʵ�֣�����������д�����ʵ��
//ͨ����ͬ�ĺ������ã��߲�ͬ��·��
class AbstractDrink
{
public:
	//��ˮ���麯��
	virtual void Boil() = 0;
	//����
	virtual void  Brew() = 0;

	//���뱭��
	virtual void PourInCup() = 0;

	//���븨���Ĵ���
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
	//����ʵ��
	//��ˮ
	virtual void Boil()
	{
		cout << "��ˮ" << endl;

	}
	//����
	virtual void  Brew()
	{
		cout << "���ݿ���" << endl;

	}

	//���뱭��
	virtual void PourInCup()
	{
		cout << "���뱭��" << endl;

	}

	//���븨���Ĵ���
	virtual void Putst()
	{
		cout << "����ţ�̺���" << endl;

	}
};
class Tea :public AbstractDrink
{
public:
	//����ʵ��
	//��ˮ
	virtual void Boil()
	{
		cout << "��ˮ" << endl;

	}
	//����
	virtual void  Brew()
	{
		cout << "���ݲ�Ҷ" << endl;

	}

	//���뱭��
	virtual void PourInCup()
	{
		cout << "���뱭��" << endl;

	}

	//���븨���Ĵ���
	virtual void Putst()
	{
		cout << "��������" << endl;

	}
};
//��������
void dowork(AbstractDrink* a)
{
	a->makedrink();
	delete a;//�ͷſռ�����ͷŵ�
}
void test01()
{
	//��������
	dowork(new Coffee);
	dowork(new Tea);
}
int main()
{
	test01();
	system("pause");
		return 0;
}