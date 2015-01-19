#pragma once
#include "MVIGameObject.h"
#include <string>

using namespace std;

class MVCard : public MVIGameObject
{
public:
	MVCard(string name);
	~MVCard();
	string getName() const;
protected:
	const string name;
};

