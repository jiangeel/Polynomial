#include "stdafx.h"
#include "Polynomial.h"

//默认长度为1,F(x)=0的多项式
Polynomial::Polynomial()
{
	Node newNode(0, 0);
	myTerm.push_back(newNode);
	myDegree = 0;
}

//重载拷贝构造函数
Polynomial::Polynomial(const Polynomial & pm)
{
	this->myTerm = pm.myTerm;
	this->myDegree = pm.myDegree;
}

//重载=号
void Polynomial::operator=(const Polynomial & pm)
{
	this->myTerm = pm.myTerm;
	this->myDegree = pm.myDegree;
}

//用一个二维数组初始化多项式链表
Polynomial::Polynomial(const int a[][2],const unsigned &len)
{
	if (len==0)//长度为零的多项式
	{
		Polynomial();
		return;
	}
	else//长度不为零的多项式
	{
		myDegree = a[0][1];
		for (unsigned i = 0 ; i <len; i++)//从后往前插入
		{
			if (a[i][1]>myDegree)//寻找到最大的系数作为多项式的阶
			{
				myDegree = a[i][1];
			}
			Node newnNode(a[i][0], a[i][1]);
			myTerm.push_back(newnNode);
		}
	}

}


void Polynomial::display()
{
	cout << "F(x) = ";
	if (myTerm.size()==1 && myTerm.front().coef==0)//多项式只有一项且为零
	{
		cout << "0";
	}
	else//多项式有多项
	{
		for (list<Node>::iterator i=myTerm.begin();i!=myTerm.end();i++)
		{
			cout.setf(ios::showpos);//控制正系数输出"+"号
			if (i->coef != 0)//系数为零时直接跳过
			{
				if (i->expo == 0)//幂次为0时只显示系数
				{
					cout<< i->coef<< " ";
				}
				else if (i->coef==1)//系数为1时不显示x^
				{
					cout <<"+"<< "X^" << i->expo << " ";
				}
				else if (i->coef == -1)//系数为-1时显示-x^
				{
					cout << "-" << "X^" << i->expo << " ";
				}
				else
				{
					cout << i->coef << "X^" << i->expo << " ";
				}
			}

		}

	}
	cout.unsetf(ios::showpos);
	cout <<"     degree: "<<myDegree<< endl;
}

//重载+号实现两个按幂次降序的多项式求和,如未排序可先用sort()
Polynomial  Polynomial::operator+(const Polynomial & pm)
{
	//F和G做为两个原多项式求和,返回修改后的F
	Polynomial G = pm;	//拷贝一份防止破坏原多项式
	list<Node>::iterator iF = myTerm.begin();
	list<Node>::iterator iG=G.myTerm.begin();
	while (iG!=G.myTerm.end() && iF!=myTerm.end())//两个多项式都还有节点
	{
		while (iF != myTerm.end() && iG->expo<iF->expo)//G的第一项幂次大于F的
		{
			iF++;
		}

		if (iF==myTerm.end())//F遍历完了,G剩下的项都比F最后项小
		{
			myTerm.insert(iF, iG, G.myTerm.end());//将G剩下的全部插入到F末尾
		}
		else if (iG->expo ==iF->expo)//上述循环停止是因为幂次相等
		{
			iF->coef = iF->coef + iG->coef;//将F与G同幂项合并
		}
		else if (iG->expo > iF->expo)//上述循环停止是因为F的幂次小于iG了
		{
			iF=myTerm.insert(iF,*iG);//将iG节点插入F,并将iF指向新插入的节点
		}

		iG++;//处理完一个节点,处理下一个
	}
	return *this;

}



bool howToSort(Node a, Node b)
{
	return a.expo > b.expo;
}
void Polynomial::sort()
{
	myTerm.sort(howToSort);
}




Polynomial::~Polynomial()
{
}
