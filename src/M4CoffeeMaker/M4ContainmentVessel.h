#pragma once

#include "Generic/ContainmentVessel.h"

class M4CoffeeMakerAPI;

class M4ContainmentVessel : public ContainmentVessel
{
public:
	M4ContainmentVessel();
	virtual ~M4ContainmentVessel(); 
	bool IsReady();
private:
	M4CoffeeMakerAPI *api;
};
