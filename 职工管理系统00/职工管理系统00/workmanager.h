#pragma once
#include<iostream>
#include"worker.h"
#include"boss.h"
#include"employee.h"
#include"manager.h"
#include<fstream>
#define file "file.txt"
using namespace std;

class workmanager
{
public:
	workmanager();

	void showmeun();

	void exitsystem();

	int wnum;//ְ������

	worker** warry;//ְ������ָ��

	void add();//���Ӻ���

	void save();

	bool filesempty;

	int getnum();

	void inti();

	void show();

	int judge(int n);

	void dele();

	void mod();

	void find();

	void sort();

	void clean();

	~workmanager();
};