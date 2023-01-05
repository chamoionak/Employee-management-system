#pragma once
#include<iostream>
#include"worker.h"

class manager:public worker
{
public:
	manager(int aid, string aname, int amid);

	virtual void showperson();

	virtual string getwname();
};