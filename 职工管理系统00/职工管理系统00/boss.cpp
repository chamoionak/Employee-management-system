#include<iostream>
#include"boss.h"
using namespace std;

boss::boss(int aid, string aname, int amid)
{
	id = aid;
	name = aname;
	mid = amid;
}

void boss::showperson()
{
	cout << "ְ�����:" << id
		<< "\tְ������:" << name
		<< "\t��λ:" << getwname()
		<< "\t��λְ��:����˾���е�����" << endl;
}

string boss::getwname()
{
	return string("�ϰ�");
}
