#pragma once
#include "MVCard.h"
#include "../Enum/MVEnum.h"
class MVBuilding : public MVCard
{
public:
	MVBuilding(string name, int price, MVEnum::Colors color);
	~MVBuilding();
	int getPrice() const;
	MVEnum::Colors getColor() const;
protected:
	const int cost;
	const MVEnum::Colors color;
};

