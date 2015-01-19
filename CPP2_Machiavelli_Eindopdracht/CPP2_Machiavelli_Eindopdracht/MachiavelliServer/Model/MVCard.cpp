//
#include "MVCard.h"

//

//
using namespace std;

MVCard::MVCard(string name) : name(name)
{
}

MVCard::~MVCard()
{
}
 
string MVCard::getName() const
{
	return name;
}
