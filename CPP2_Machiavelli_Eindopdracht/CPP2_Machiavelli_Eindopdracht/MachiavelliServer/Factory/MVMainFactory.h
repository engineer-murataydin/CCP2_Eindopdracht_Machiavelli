#pragma once

//
#include <vector>
#include <memory>

//
#include "../Model/MVCharacter.h"
#include "../Model/MVBuilding.h"

//
using namespace std;

class MVMainFactory
{
public:
	~MVMainFactory();

	static vector<shared_ptr<MVCharacter>> loadCharacters();
	static vector<shared_ptr<MVBuilding>> loadBuildings();

private:
	MVMainFactory();
};