#pragma once
#include "MVCard.h"
#include "../Enum/MVEnum.h"

class MVCharacter : public MVCard
{
public:
	MVCharacter(MVEnum::Characters order, string name);
	virtual  ~MVCharacter();
	MVEnum::Characters getOrder() const;
private:
	const MVEnum::Characters order;
};

