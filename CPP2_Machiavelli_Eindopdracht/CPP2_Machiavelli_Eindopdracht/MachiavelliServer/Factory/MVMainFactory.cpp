//

//
#include "MVMainFactory.h"
#include "../Controller/MVFileController.h"
#include "../Model/MVSpecialBuilding.h"

//
using namespace std;

MVMainFactory::MVMainFactory() {}

MVMainFactory::~MVMainFactory() {}

vector<shared_ptr<MVCharacter>> MVMainFactory::loadCharacters()
{
	vector<shared_ptr<MVCharacter>> characters;
	vector<vector<string>> characterData = MVFileController::readInputFile("MachiavelliServer/ExternSourceFiles/karakterkaarten.csv");

	for (int i = 0; i < characterData.size(); i++)
	{
		characters.push_back(shared_ptr<MVCharacter>(new MVCharacter(stoi(characterData[i][0]), characterData[i][1])));
	}
	return characters;
}

vector<shared_ptr<MVBuilding>> MVMainFactory::loadBuildings()
{
	vector<shared_ptr<MVBuilding>> buildings;
	vector<vector<string>> buildingData = MVFileController::readInputFile("MachiavelliServer/ExternSourceFiles/bouwkaarten.csv");

	for (int i = 0; i < buildingData.size(); i++)
	{
		if (buildingData[i].size() == 3)
		{
			buildings.push_back(shared_ptr<MVBuilding>(new MVBuilding(buildingData[i][0], stoi(buildingData[i][1]), MVEnum::getColor(buildingData[i][2]))));
		}
		else if (buildingData[i].size() == 4)
		{
			buildings.push_back(shared_ptr<MVSpecialBuilding>(new MVSpecialBuilding(buildingData[i][0], stoi(buildingData[i][1]), MVEnum::getColor(buildingData[i][2]), buildingData[i][3])));
		}
	}
	return buildings;
}
