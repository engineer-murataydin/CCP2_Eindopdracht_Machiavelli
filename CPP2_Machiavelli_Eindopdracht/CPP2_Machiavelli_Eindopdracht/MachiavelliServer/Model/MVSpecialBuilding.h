#pragma once
#include "MVBuilding.h"
#include "../Enum/MVEnum.h"

class MVSpecialBuilding :
	public MVBuilding
{
public:
	MVSpecialBuilding(string name, int price, MVEnum::Colors color, string description);
	virtual ~MVSpecialBuilding();

protected:
	string description;
};

