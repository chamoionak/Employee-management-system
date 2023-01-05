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
	cout << "职工编号:" << id
		<< "\t职工姓名:" << name
		<< "\t岗位:" << getwname()
		<< "\t岗位职责:完成老板交给的任务，并且下发任务给普通员工" << endl;
}

string manager::getwname()
{
	return string("经理");
}