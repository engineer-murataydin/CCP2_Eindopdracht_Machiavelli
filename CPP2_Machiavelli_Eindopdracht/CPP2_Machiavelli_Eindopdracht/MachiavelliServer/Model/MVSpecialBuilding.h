#pragma once

//
#include "MVBuilding.h"
#include "../Enum/MVEnum.h"

//

//
using namespace std;

class MVSpecialBuilding :
	public MVBuilding
{
public:
	MVSpecialBuilding(string name, int price, MVEnum::Colors color, string description);
	virtual ~MVSpecialBuilding();
	string getDescription() const;
protected:
	const string description;
};

