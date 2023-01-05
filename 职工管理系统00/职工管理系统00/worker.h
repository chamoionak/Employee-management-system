#pragma once
#include<iostream>
using namespace std;

class worker
{
public:
	virtual void showperson()=0;

	virtual string getwname()=0;

	int id;
	 
	string name;

	int mid;
};