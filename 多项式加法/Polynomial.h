#pragma once
#include <list>
#include <iostream>
using namespace std;
class Node
{
public:
	Node(int co = 0, int ex = 0)
	{
		coef = co;
		expo = ex;
	};
	int coef;//系数
	unsigned expo;//幂
};
class Polynomial
{
public:
	Polynomial();
	Polynomial(const int a[][2], const unsigned &len);//用一个二维数组初始化多项式链表
	Polynomial(const Polynomial &pm);
	void display();//打印多项式
	Polynomial &operator+( const Polynomial & pm);//重载+号,实现多项式求和
	void operator=(const Polynomial &pm);//重载=号
	void sort();//将多项式按次数降序排列
	~Polynomial();
private:
	int myDegree;//多项式的阶(最高次幂)
	list<Node> myTerm;//一个用list实现的多项式

};

