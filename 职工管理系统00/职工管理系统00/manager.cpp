#include<iostream>
#include"manager.h"
using namespace std;

manager::manager(int aid, string aname, int amid)
{
	id = aid;
	name = aname;
	mid = amid;
}

void manager::showperson()
{
	cout << "ְ�����:" << id
		<< "\tְ������:" << name
		<< "\t��λ:" << getwname()
		<< "\t��λְ��:����ϰ彻�������񣬲����·��������ͨԱ��" << endl;
}

string manager::getwname()
{
	return string("����");
}