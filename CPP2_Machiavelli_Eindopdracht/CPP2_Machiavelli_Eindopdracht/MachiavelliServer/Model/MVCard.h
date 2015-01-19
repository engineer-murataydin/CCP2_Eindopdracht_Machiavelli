#pragma once
#include "MVIGameObject.h"
#include <string>

using namespace std;

class MVCard :
	public MVIGameObject
{
public:
	MVCard(string name);
	virtual ~MVCard();

protected:
	string name;
};

