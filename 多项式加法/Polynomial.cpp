#include "stdafx.h"
#include "Polynomial.h"

//Ĭ�ϳ���Ϊ1,F(x)=0�Ķ���ʽ
Polynomial::Polynomial()
{
	Node newNode(0, 0);
	myTerm.push_back(newNode);
	myDegree = 0;
}

//���ؿ������캯��
Polynomial::Polynomial(const Polynomial & pm)
{
	this->myTerm = pm.myTerm;
	this->myDegree = pm.myDegree;
}

//����=��
void Polynomial::operator=(const Polynomial & pm)
{
	this->myTerm = pm.myTerm;
	this->myDegree = pm.myDegree;
}

//��һ����ά�����ʼ������ʽ����
Polynomial::Polynomial(const int a[][2],const unsigned &len)
{
	if (len==0)//����Ϊ��Ķ���ʽ
	{
		Polynomial();
		return;
	}
	else//���Ȳ�Ϊ��Ķ���ʽ
	{
		myDegree = a[0][1];
		for (unsigned i = 0 ; i <len; i++)//�Ӻ���ǰ����
		{
			if (a[i][1]>myDegree)//Ѱ�ҵ�����ϵ����Ϊ����ʽ�Ľ�
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
	if (myTerm.size()==1 && myTerm.front().coef==0)//����ʽֻ��һ����Ϊ��
	{
		cout << "0";
	}
	else//����ʽ�ж���
	{
		for (list<Node>::iterator i=myTerm.begin();i!=myTerm.end();i++)
		{
			cout.setf(ios::showpos);//������ϵ�����"+"��
			if (i->coef != 0)//ϵ��Ϊ��ʱֱ������
			{
				if (i->expo == 0)//�ݴ�Ϊ0ʱֻ��ʾϵ��
				{
					cout<< i->coef<< " ";
				}
				else if (i->coef==1)//ϵ��Ϊ1ʱ����ʾx^
				{
					cout <<"+"<< "X^" << i->expo << " ";
				}
				else if (i->coef == -1)//ϵ��Ϊ-1ʱ��ʾ-x^
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

//����+��ʵ���������ݴν���Ķ���ʽ���,��δ���������sort()
Polynomial  Polynomial::operator+(const Polynomial & pm)
{
	//F��G��Ϊ����ԭ����ʽ���,�����޸ĺ��F
	Polynomial G = pm;	//����һ�ݷ�ֹ�ƻ�ԭ����ʽ
	list<Node>::iterator iF = myTerm.begin();
	list<Node>::iterator iG=G.myTerm.begin();
	while (iG!=G.myTerm.end() && iF!=myTerm.end())//��������ʽ�����нڵ�
	{
		while (iF != myTerm.end() && iG->expo<iF->expo)//G�ĵ�һ���ݴδ���F��
		{
			iF++;
		}

		if (iF==myTerm.end())//F��������,Gʣ�µ����F�����С
		{
			myTerm.insert(iF, iG, G.myTerm.end());//��Gʣ�µ�ȫ�����뵽Fĩβ
		}
		else if (iG->expo ==iF->expo)//����ѭ��ֹͣ����Ϊ�ݴ����
		{
			iF->coef = iF->coef + iG->coef;//��F��Gͬ����ϲ�
		}
		else if (iG->expo > iF->expo)//����ѭ��ֹͣ����ΪF���ݴ�С��iG��
		{
			iF=myTerm.insert(iF,*iG);//��iG�ڵ����F,����iFָ���²���Ľڵ�
		}

		iG++;//������һ���ڵ�,������һ��
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
