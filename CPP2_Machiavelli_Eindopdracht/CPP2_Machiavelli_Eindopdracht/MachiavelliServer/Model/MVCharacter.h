#pragma once
#include "MVCard.h"

class MVCharacter :
	public MVCard
{
public:
	MVCharacter(int id, string name);
	~MVCharacter();
};

