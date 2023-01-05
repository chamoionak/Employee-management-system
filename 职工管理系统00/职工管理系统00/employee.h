#pragma once
#include"worker.h"
#include<iostream>

class employee :public worker
{
public:
	employee(int aid, string aname, int amid);

	virtual void showperson();

	virtual string getwname();
};