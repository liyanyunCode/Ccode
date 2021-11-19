#include<iostream>
#include<string>
#pragma once
#include"MyArrsy.hpp"
using namespace std;
//实现一个通用的数组类
//可以对内置数据类型以及自定义数据类型进行存储
//将数组中的数据存储到堆区
//构造函数可以传入数组的容量
//提供对应的拷贝构造函数以及operator=防止浅拷贝问题
//提供尾插法和尾删法对数组中的数据进行增加和删除
//可以通过下标的方式访问数组中的元素
//可以获取数组中当前元素个数和数组的容量

void test03()
{
	MyArray <int>arr1(5);

}
int main()
{

	test03();
	system("pause");
	return 0;

}