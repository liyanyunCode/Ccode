#include<iostream>
#include<string>
using namespace std;
//案列描述
//电脑主要组成部件有CPU，显卡，内存条
//将每个零件封装出抽象基类，并且提供不同的厂商生产不同的零件，例如Intel Lenovo
//创建电脑类提供让电脑工作的函数，并且第哦啊用每个零件工作的接口
//测试时组装三台不同的电脑进行工作

class CPU//抽象的CPU类
{
public:
	virtual void caculate() = 0;//抽象的计算的函数


};
class VideoCard//抽象的显卡类
{
public:
	virtual void display() = 0;//抽象的计算的函数


};
class Memory//抽象的内存条类
{
public:
	virtual void storage() = 0;//抽象的计算的函数


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
	void work()//工作函数，调用接口
	{
		m_cpu->caculate();
		m_vc->display();
		m_me->storage();
	}
	//提供一个析构函数来释放三个电脑零件
	~Computer()
	{
		//释放CPU零件
		if (m_cpu != NULL)
		{
			delete m_cpu;
			m_cpu = NULL;
		}
		//释放VC零件
		if (m_vc != NULL)
		{
			delete m_cpu;
			m_vc = NULL;
		}
		//释放ME零件
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

//Intel 厂商
class intelcpu :public CPU
{
public:
	virtual void caculate()
	{
		cout << "intelcpu开始工作" << endl;

	}
};
class intelvideocard :public VideoCard
{
public:
	virtual void display()
	{
		cout << "intelvideocard开始显示" << endl;

	}
};
class intelmemory :public Memory
{
public:
	virtual void storage()
	{
		cout << "intel内存条开始工作" << endl;

	}
};

class lenovocpu :public CPU
{
public:
	virtual void caculate()
	{
		cout << " lenovo开始工作" << endl;

	}
};
class lenovovideocard :public VideoCard
{
public:
	virtual void display()
	{
		cout << " lenovovideocard开始显示" << endl;

	}
};
class  lenovomemory :public Memory
{
public:
	virtual void storage()
	{
		cout << " lenovo内存条开始工作" << endl;

	}
};
void test01()
{
	 //第一台电脑零件
	CPU* intelCpu = new intelcpu;
	//父类指针指向子类对象
	VideoCard* intelCard = new intelvideocard;
	Memory* intelmem = new intelmemory;
	  //创建第一台电脑
	Computer* computer = new Computer(intelCpu, intelCard, intelmem);
	computer->work();
	delete computer;
	//第二台电脑一样的操作或是不同的创建方法Computer * computer2=new Computer(new lenovocpu,new lenovovideocard,new lenovomemory)
}
