#pragma once

#include "Generic/UserInterface.h"




class M4CoffeeMakerAPI;

class M4UserInterface : public UserInterface
{
public:
	M4UserInterface();
	virtual ~M4UserInterface();
	virtual bool IsBrewButtonPushed();
	virtual void StartBrewing();
private:
	M4CoffeeMakerAPI *api;
};
