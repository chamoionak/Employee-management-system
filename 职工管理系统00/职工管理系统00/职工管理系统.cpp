#include"workmanager.h"
#include<iostream>
using namespace std;
int main()
{
	workmanager m;
	int choice = 0;
	while (true)
	{
		m.showmeun();
		cout << "ÇëÑ¡ÔñÑ¡Ïî£º" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:
			m.exitsystem();
			break;
		case 1:
			m.add();
			break;
		case 2:
			m.show();
			break;
		case 3:
			m.dele();
			break;
		case 4:
			m.mod();
			break;
		case 5:
			m.find();
			break;
		case 6:
			m.sort();
			break;
		case 7:
			m.clean();
			break;
		default:
			system("cls");
			break;
		}
	}
	return 0;
}