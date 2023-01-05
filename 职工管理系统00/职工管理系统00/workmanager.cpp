#include"workmanager.h"
#include<iostream>

workmanager::workmanager()
{
	ifstream ifs;
	ifs.open(file, ios::in);
	if (!ifs.is_open())//�ļ�������
	{
		this->wnum = 0;
		this->warry = NULL;
		this->filesempty = true;
		ifs.close();
		return;
	}

	char ch;
	ifs >> ch;
	if (ifs.eof())//�ļ����ڣ����ݲ�����
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
	cout << "*****��ӭʹ��ְ������ϵͳ*****" << endl;
	cout << "*******0-�˳��������*********" << endl;
	cout << "*******1-����ְ����Ϣ*********" << endl;
	cout << "*******2-��ʾְ����Ϣ*********" << endl;
	cout << "*******3-ɾ����ְְ��*********" << endl;
	cout << "*******4-�޸�ְ����Ϣ*********" << endl;
	cout << "*******5-����ְ����Ϣ*********" << endl;
	cout << "*******6-���ձ������*********" << endl;
	cout << "*******7-��������ĵ�*********" << endl;
	cout << "******************************" << endl;
}

void workmanager::exitsystem()
{
	cout << "��ӭ�´�ʹ��ְ������ϵͳ��" << endl;
	system("pause");
	exit(0);
}

void workmanager::add()
{
	cout << "��������ӵ�������";
	int add = 0;
	cin >> add;

	if (add > 0)
	{
		int newsize = this->wnum + add;//�¿ռ�=ԭ��ְ������+��������
		worker** newspace = new worker *[newsize];//�����¿ռ䶯̬����

		if (warry != NULL)//���ԭ������ǿ�
		{
			for (int i = 0; i < this->wnum; ++i)
			{
				newspace[i] = warry[i];//��ԭ�����鸴�Ƶ��¿ռ�
			}
		}
		for (int i = 0; i < add; ++i)
		{
			int id;
			string name;
			int dselect;

			cout << "��������Ϣ��" << endl;
			cout << "�������" << i + 1 << "����ְ����ţ�";
			cin >> id;
			cout << "�������" << i + 1 << "����ְ�����֣�";
			cin >> name;
			cout << "�������" << i + 1 << "����ְ��ְ�ܲ��ţ�" << endl;
			cout << "1.��ͨԱ��" << endl;
			cout << "2.�ϰ�" << endl;
			cout << "3.����" << endl;
			cin >> dselect;

			worker* w = NULL;//���ٻ�����ָ��Ϊ��
			switch (dselect)
			{
			case 1:
				w = new employee(id, name, 1);//������ָ��ָ��������
				break;
			case 2:
				w = new boss(id, name, 2);
				break;
			case 3:
				w = new manager(id, name, 3);
				break;
			}

			newspace[this->wnum + i] = w;//�������ݸ��Ƶ��¿ռ�ĺ�����
		}

		delete[]this->warry;//�ͷ�ԭ������
		this->warry = newspace;//���¿ռ临�Ƶ�ԭ��������
		this->wnum = newsize;//�����������Ƶ�ԭ��������

		cout << "��ӳɹ���" << endl;
		cout << "�ɹ����" << add << "����ְ��" << endl;
		this->save();
	}
	else
	{
		cout << "����ʧ��" << endl;
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
		cout << "�ļ������ڣ����������룡" << endl;
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
	cout << "�����뽫Ҫɾ����ְ����ţ�";
	int choice;
	cin >> choice;
	int dex = judge(choice);

	if (filesempty == true)
	{
		cout << "�ļ������ڣ����������룡" << endl;
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
			cout << "���޴��ˣ�" << endl;
		}
	}
	system("pause");
	system("cls");
}
void workmanager::mod()
{
	int x;
	cout << "������Ҫ�޸ĵ�ְ����ţ�";
	cin >> x;
	int in = judge(x);
	if (filesempty == true)
	{
		cout << "�ļ������ڣ����������룡" << endl;
	}
	else
	{
		if (in != -1)
		{
			delete this->warry[in];
			int hid;
			string hname;
			int hdselect;

			cout << "���޸���Ϣ��" << endl;
			cout << "���޸ĵ�" << in + 1<< "����ְ����ţ�";
			cin >> hid;
			cout << "���޸ĵ�" << in + 1<< "����ְ�����֣�";
			cin >> hname;
			cout << "���޸ĵ�" << in + 1<< "����ְ��ְ�ܲ��ţ�" << endl;
			cout << "1.��ͨԱ��" << endl;
			cout << "2.�ϰ�" << endl;
			cout << "3.����" << endl;
			cin >> hdselect;

			worker* w = NULL;//���ٻ�����ָ��Ϊ��
			switch (hdselect)
			{
			case 1:
				w = new employee(hid, hname, 1);//������ָ��ָ��������
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
			cout << "�޸ĳɹ���" << endl;
		}
		else
		{
			cout << "���޴��ˣ�" << endl;
		}
	}
	system("pause");
	system("cls");
}

void workmanager::find()
{
	int c;
	cout << "��ѡ����ҷ�ʽ��" << endl;
	cout << "1.���ݱ�Ų���" << endl;
	cout << "2.������������" << endl;
	cin >> c;

	if (filesempty == true)
	{
		cout << "�ļ������ڣ����������룡" << endl;
	}
	else if (c == 1)
	{
		cout << "�������ţ�";
		int a;
		cin >> a;
		int b = judge(a);
		if (b != -1)
		{
			this->warry[b]->showperson();
		}
		else
		{
			cout << "���޴��ˣ�" << endl;
		}
	}
	else if (c == 2)
	{
		cout << "������������";
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
		cout << "����ѡ������" << endl;
	}
	system("pause");
	system("cls");
}

void workmanager::sort()
{
	if (filesempty == true)
	{
		cout << "�ļ������ڣ����������룡" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "��ѡ������ʽ��" << endl;
		cout << "1.��������" << endl;
		cout << "2.��������" << endl;
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
	cout << "����ɹ���" << endl;
	this->save();
	this->show();
}

void workmanager::clean()
{
	cout << "�Ƿ�Ҫ��գ�" << endl;
	cout << "1.ȷ��" << endl;
	cout << "2.ȡ��" << endl;
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
		cout << "��ճɹ���" << endl;
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