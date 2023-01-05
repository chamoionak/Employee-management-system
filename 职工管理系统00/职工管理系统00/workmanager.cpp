#include"workmanager.h"
#include<iostream>

workmanager::workmanager()
{
	ifstream ifs;
	ifs.open(file, ios::in);
	if (!ifs.is_open())//文件不存在
	{
		this->wnum = 0;
		this->warry = NULL;
		this->filesempty = true;
		ifs.close();
		return;
	}

	char ch;
	ifs >> ch;
	if (ifs.eof())//文件存在，数据不存在
	{
		this->wnum = 0;
		this->warry = NULL;
		this->filesempty = true;
		ifs.close();
		return;
	}

	this->wnum =this->getnum();
	this->warry = new worker * [this->wnum];
	this->inti();

}
void workmanager::showmeun()
{
	cout << "******************************" << endl;
	cout << "*****欢迎使用职工管理系统*****" << endl;
	cout << "*******0-退出管理程序*********" << endl;
	cout << "*******1-增加职工信息*********" << endl;
	cout << "*******2-显示职工信息*********" << endl;
	cout << "*******3-删除离职职工*********" << endl;
	cout << "*******4-修改职工信息*********" << endl;
	cout << "*******5-查找职工信息*********" << endl;
	cout << "*******6-按照编号排序*********" << endl;
	cout << "*******7-清空所有文档*********" << endl;
	cout << "******************************" << endl;
}

void workmanager::exitsystem()
{
	cout << "欢迎下次使用职工管理系统！" << endl;
	system("pause");
	exit(0);
}

void workmanager::add()
{
	cout << "请输入添加的人数：";
	int add = 0;
	cin >> add;

	if (add > 0)
	{
		int newsize = this->wnum + add;//新空间=原有职工人数+增加人数
		worker** newspace = new worker *[newsize];//开辟新空间动态数组

		if (warry != NULL)//如果原有数组非空
		{
			for (int i = 0; i < this->wnum; ++i)
			{
				newspace[i] = warry[i];//将原有数组复制到新空间
			}
		}
		for (int i = 0; i < add; ++i)
		{
			int id;
			string name;
			int dselect;

			cout << "请输入信息：" << endl;
			cout << "请输入第" << i + 1 << "个新职工编号：";
			cin >> id;
			cout << "请输入第" << i + 1 << "个新职工名字：";
			cin >> name;
			cout << "请输入第" << i + 1 << "个新职工职能部门：" << endl;
			cout << "1.普通员工" << endl;
			cout << "2.老板" << endl;
			cout << "3.经理" << endl;
			cin >> dselect;

			worker* w = NULL;//开辟基类新指针为空
			switch (dselect)
			{
			case 1:
				w = new employee(id, name, 1);//将基类指针指向派生类
				break;
			case 2:
				w = new boss(id, name, 2);
				break;
			case 3:
				w = new manager(id, name, 3);
				break;
			}

			newspace[this->wnum + i] = w;//将新内容复制到新空间的后面里
		}

		delete[]this->warry;//释放原有数组
		this->warry = newspace;//将新空间复制到原有数组中
		this->wnum = newsize;//将新人数复制到原有人数中

		cout << "添加成功！" << endl;
		cout << "成功添加" << add << "个新职工" << endl;
		this->save();
	}
	else
	{
		cout << "输入失误！" << endl;
	}
	system("pause");
	system("cls");
}
void workmanager::save()
{
	ofstream ofs;
	ofs.open(file, ios::out);
	for (int i = 0; i < this->wnum; ++i)
	{
		ofs << this->warry[i]->id << " "
			<< this->warry[i]->name << " "
			<< this->warry[i]->mid << endl;
	}
	ofs.close();
}
int workmanager::getnum()
{
	int num = 0;
	ifstream ifs;
	ifs.open(file,ios::in);

	int cid;
	string cname;
	int cdid;
	while (ifs >> cid && ifs >> cname && ifs >> cdid)
	{
		num++;
	}
	return num;
}
void workmanager::inti()
{
	ifstream ifs;
	ifs.open(file, ios::in);

	int did;
	string dname;
	int ddid;
	int index = 0;

	while (ifs >> did && ifs >> dname && ifs >> ddid)
	{
		worker* m = NULL;
		if (ddid == 1)
		{
			m =new employee(did, dname, ddid);
		}
		if (ddid == 2)
		{
			m =new boss(did, dname, ddid);
		}
		if (ddid == 3)
		{
			m =new manager(did, dname, ddid);
		}
		this->warry[index] = m;
		index++;
	}
	ifs.close();
}
void workmanager::show()
{
	if (filesempty == true)
	{
		cout << "文件不存在，请重新输入！" << endl;
	}
	else
	{
		for (int i = 0; i < wnum; ++i)
		{
			this->warry[i]->showperson();
		}
	}
	system("pause");
	system("cls");
}

int workmanager::judge(int n)
{
	int index = -1;

	for (int i = 0; i < this->wnum; ++i)
	{
		if (this->warry[i]->id == n)
		{
			index = i;
		}
	}
	return index;
}

void workmanager::dele()
{
	cout << "请输入将要删除的职工编号：";
	int choice;
	cin >> choice;
	int dex = judge(choice);

	if (filesempty == true)
	{
		cout << "文件不存在，请重新输入！" << endl;
	}
	else
	{
		if (dex != -1)
		{
			for (int i = dex; i < this->wnum - 1; ++i)
			{
				this->warry[i] = this->warry[i + 1];
			}
			this->wnum--;
			this->save();
		}
		else
		{
			cout << "查无此人！" << endl;
		}
	}
	system("pause");
	system("cls");
}
void workmanager::mod()
{
	int x;
	cout << "输入想要修改的职工编号：";
	cin >> x;
	int in = judge(x);
	if (filesempty == true)
	{
		cout << "文件不存在，请重新输入！" << endl;
	}
	else
	{
		if (in != -1)
		{
			delete this->warry[in];
			int hid;
			string hname;
			int hdselect;

			cout << "请修改信息：" << endl;
			cout << "请修改第" << in + 1<< "个新职工编号：";
			cin >> hid;
			cout << "请修改第" << in + 1<< "个新职工名字：";
			cin >> hname;
			cout << "请修改第" << in + 1<< "个新职工职能部门：" << endl;
			cout << "1.普通员工" << endl;
			cout << "2.老板" << endl;
			cout << "3.经理" << endl;
			cin >> hdselect;

			worker* w = NULL;//开辟基类新指针为空
			switch (hdselect)
			{
			case 1:
				w = new employee(hid, hname, 1);//将基类指针指向派生类
				break;
			case 2:
				w = new boss(hid, hname, 2);
				break;
			case 3:
				w = new manager(hid, hname, 3);
				break;
			}
			this->warry[in] = w;
			this->save();
			cout << "修改成功！" << endl;
		}
		else
		{
			cout << "查无此人！" << endl;
		}
	}
	system("pause");
	system("cls");
}

void workmanager::find()
{
	int c;
	cout << "请选择查找方式：" << endl;
	cout << "1.根据编号查找" << endl;
	cout << "2.根据姓名查找" << endl;
	cin >> c;

	if (filesempty == true)
	{
		cout << "文件不存在，请重新输入！" << endl;
	}
	else if (c == 1)
	{
		cout << "请输入编号：";
		int a;
		cin >> a;
		int b = judge(a);
		if (b != -1)
		{
			this->warry[b]->showperson();
		}
		else
		{
			cout << "查无此人！" << endl;
		}
	}
	else if (c == 2)
	{
		cout << "请输入姓名：";
		string aname;
		cin >> aname;

		for (int i = 0; i < wnum; ++i)
		{
			if (this->warry[i]->name == aname)
			{
				this->warry[i]->showperson();
			}
		}
	}
	else
	{
		cout << "输入选项有误！" << endl;
	}
	system("pause");
	system("cls");
}

void workmanager::sort()
{
	if (filesempty == true)
	{
		cout << "文件不存在，请重新输入！" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "请选择排序方式：" << endl;
		cout << "1.升序排序" << endl;
		cout << "2.降序排序" << endl;
		int s = 0;
		cin >> s;
		for (int i = 0; i < this->wnum; ++i)
		{
			int min = i;
			for (int j = i + 1; j < this->wnum; ++j)
			{
				if (s == 1)
				{
					if (this->warry[j]->id < this->warry[min]->id)
					{
						min = j;
					}
				}
				else if (s == 2)
				{
					 if (this->warry[j]->id > this->warry[min]->id)
					 { 
						min = j;
					 }
				}
			}
			if (min != i)
			{
				worker* temp = this->warry[i];
				this->warry[i] = this->warry[min];
				this->warry[min] =temp;
			}
		}

	}
	cout << "排序成功！" << endl;
	this->save();
	this->show();
}

void workmanager::clean()
{
	cout << "是否要清空？" << endl;
	cout << "1.确定" << endl;
	cout << "2.取消" << endl;
	int s;
	cin >> s;
	if (s == 1)
	{
		ofstream ofs;
		ofs.open(file, ios::trunc);
		ofs.close();
		if (this->warry != NULL)
		{
			for (int i = 0; i < this->wnum; ++i)
			{
				if (this->warry[i] != NULL)
				{
					delete warry[i];
				}
			}
			this->wnum = 0;
			delete this->warry;
			this->warry = NULL;
			this->filesempty = true;
		}
		cout << "清空成功！" << endl;
	}
	system("pause");
	system("cls");
}
workmanager::~workmanager()
{
	if (warry != NULL)
	{
		delete[]this->warry;
		this->warry = NULL;
	}
}