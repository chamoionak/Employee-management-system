#include"employee.h"
#include<iostream>
using namespace std;

employee::employee(int aid, string aname, int amid)
{
	id = aid;
	name = aname;
	mid = amid;
}

void employee::showperson()
{
	cout << "ְ�����:" << id
		<< "\tְ������:" << name
		<< "\t��λ:" <<getwname()
		<< "\t��λְ��:��ɾ�����������" << endl;
}

string employee::getwname()
{
	return string("��ͨԱ��");
}
