// ����ʽ�ӷ�.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include "Polynomial.h"
using namespace std;
int main()
{
	//��ʼ����������ʽ��תΪ����,Ȼ���ӡ
	int f[][2] = { { 8,5 } ,{ 7,4 } ,{ 3,2 },{ 5,0 } };
	int g[][2] = { { 9,6 } ,{ 2,5 } ,{ 5,4 },{ 1,1 },{2,0} };
	Polynomial F(f, 4);
	Polynomial G(g, 5);
	cout << "����ʽ1:" << endl;
	F.display();
	cout << endl<<"����ʽ2:" << endl;
	G.display();

	//����������ʽ���,Ȼ���ӡ
	Polynomial H;
	H = F + G;
	cout << endl<<"��ͺ�Ķ���ʽ3:" << endl;
	H.display();
    return 0;
}

