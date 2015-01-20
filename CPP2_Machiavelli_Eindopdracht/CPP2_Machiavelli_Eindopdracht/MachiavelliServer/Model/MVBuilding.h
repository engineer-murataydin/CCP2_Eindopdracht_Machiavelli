#pragma once
#include "MVCard.h"
#include "../Enum/MVEnum.h"
class MVBuilding : public MVCard
{
public:
	MVBuilding(string name, int price, MVEnum::Colors color);
	virtual ~MVBuilding();
	int getPrice() const;
	MVEnum::Colors getColor() const;
	int giveExtraCoin();
protected:
	const int cost;
	const MVEnum::Colors color;
	int coins;
};

