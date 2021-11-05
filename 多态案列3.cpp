#include<iostream>
#include<string>
using namespace std;
//��������
//������Ҫ��ɲ�����CPU���Կ����ڴ���
//��ÿ�������װ��������࣬�����ṩ��ͬ�ĳ���������ͬ�����������Intel Lenovo
//�����������ṩ�õ��Թ����ĺ��������ҵ�Ŷ����ÿ����������Ľӿ�
//����ʱ��װ��̨��ͬ�ĵ��Խ��й���

class CPU//�����CPU��
{
public:
	virtual void caculate() = 0;//����ļ���ĺ���


};
class VideoCard//������Կ���
{
public:
	virtual void display() = 0;//����ļ���ĺ���


};
class Memory//������ڴ�����
{
public:
	virtual void storage() = 0;//����ļ���ĺ���


};
class Computer
{
public:
	Computer(CPU* cpu, VideoCard* vc, Memory* me)
	{
		m_cpu = cpu;
		m_vc = vc;
		m_me = me;
	}
	void work()//�������������ýӿ�
	{
		m_cpu->caculate();
		m_vc->display();
		m_me->storage();
	}
	//�ṩһ�������������ͷ������������
	~Computer()
	{
		//�ͷ�CPU���
		if (m_cpu != NULL)
		{
			delete m_cpu;
			m_cpu = NULL;
		}
		//�ͷ�VC���
		if (m_vc != NULL)
		{
			delete m_cpu;
			m_vc = NULL;
		}
		//�ͷ�ME���
		if (m_me != NULL)
		{
			delete m_cpu;
			m_me = NULL;
		}
	}
private:
	CPU * m_cpu;
	VideoCard* m_vc;
	Memory* m_me;

};

//Intel ����
class intelcpu :public CPU
{
public:
	virtual void caculate()
	{
		cout << "intelcpu��ʼ����" << endl;

	}
};
class intelvideocard :public VideoCard
{
public:
	virtual void display()
	{
		cout << "intelvideocard��ʼ��ʾ" << endl;

	}
};
class intelmemory :public Memory
{
public:
	virtual void storage()
	{
		cout << "intel�ڴ�����ʼ����" << endl;

	}
};

class lenovocpu :public CPU
{
public:
	virtual void caculate()
	{
		cout << " lenovo��ʼ����" << endl;

	}
};
class lenovovideocard :public VideoCard
{
public:
	virtual void display()
	{
		cout << " lenovovideocard��ʼ��ʾ" << endl;

	}
};
class  lenovomemory :public Memory
{
public:
	virtual void storage()
	{
		cout << " lenovo�ڴ�����ʼ����" << endl;

	}
};
void test01()
{
	 //��һ̨�������
	CPU* intelCpu = new intelcpu;
	//����ָ��ָ���������
	VideoCard* intelCard = new intelvideocard;
	Memory* intelmem = new intelmemory;
	  //������һ̨����
	Computer* computer = new Computer(intelCpu, intelCard, intelmem);
	computer->work();
	delete computer;
	//�ڶ�̨����һ���Ĳ������ǲ�ͬ�Ĵ�������Computer * computer2=new Computer(new lenovocpu,new lenovovideocard,new lenovomemory)
}
