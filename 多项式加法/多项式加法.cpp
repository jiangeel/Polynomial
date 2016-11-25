// 多项式加法.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include "Polynomial.h"
using namespace std;
int main()
{
	//初始化两个多项式并转为链表,然后打印
	int f[][2] = { { 8,5 } ,{ 7,4 } ,{ 3,2 },{ 5,0 } };
	int g[][2] = { { 9,6 } ,{ 2,5 } ,{ 5,4 },{ 1,1 },{2,0} };
	Polynomial F(f, 4);
	Polynomial G(g, 5);
	cout << "多项式1:" << endl;
	F.display();
	cout << endl<<"多项式2:" << endl;
	G.display();

	//将两个多项式求和,然后打印
	Polynomial H;
	H = F + G;
	cout << endl<<"求和后的多项式3:" << endl;
	H.display();
    return 0;
}

