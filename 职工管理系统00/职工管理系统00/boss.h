#pragma once
#include<iostream>
#include"worker.h"

class boss:public worker
{
public:
	boss(int aid, string aname, int amid);

	virtual void showperson();

	virtual string getwname();
};