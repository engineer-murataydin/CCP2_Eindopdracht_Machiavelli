#pragma once
#include "MVCard.h"

class MVCharacter : public MVCard
{
public:
	MVCharacter(int order, string name);
	~MVCharacter();
	int getOrder() const;
private:
	const int order;
};

