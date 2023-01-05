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
	cout << "职工编号:" << id
		<< "\t职工姓名:" << name
		<< "\t岗位:" <<getwname()
		<< "\t岗位职责:完成经理交给的任务" << endl;
}

string employee::getwname()
{
	return string("普通员工");
}
