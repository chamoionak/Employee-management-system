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
	cout << "职工编号:" << id
		<< "\t职工姓名:" << name
		<< "\t岗位:" << getwname()
		<< "\t岗位职责:管理公司所有的事物" << endl;
}

string boss::getwname()
{
	return string("老板");
}
