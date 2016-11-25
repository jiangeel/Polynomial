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
	int coef;//ϵ��
	unsigned expo;//��
};
class Polynomial
{
public:
	Polynomial();
	Polynomial(const int a[][2], const unsigned &len);//��һ����ά�����ʼ������ʽ����
	Polynomial(const Polynomial &pm);
	void display();//��ӡ����ʽ
	Polynomial &operator+( const Polynomial & pm);//����+��,ʵ�ֶ���ʽ���
	void operator=(const Polynomial &pm);//����=��
	void sort();//������ʽ��������������
	~Polynomial();
private:
	int myDegree;//����ʽ�Ľ�(��ߴ���)
	list<Node> myTerm;//һ����listʵ�ֵĶ���ʽ

};

