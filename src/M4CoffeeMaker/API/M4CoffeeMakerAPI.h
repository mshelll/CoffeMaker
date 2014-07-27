#pragma once

#include "M4APIDefines.h"

class M4CoffeeMakerAPI
{
private:
	bool BoilerStatus;
	bool BrewButtonStatus;
	bool WarmerPlateStatus;
	

public:
	static M4CoffeeMakerAPI * getInstance();
	static void removeInstance();

	int getBoilerStatus();
	int getBrewButtonStatus();
	int getWarmerPlateStatus();
	void setWarmerState(int warmerState);
	void setBoilerState(int BoilerState);
	void setIndicatorState(int indicatorState);
	void setReliefValveState(int reliefValveState);

private:
	static unsigned int  ReferenceCount;
	static M4CoffeeMakerAPI *instance;
	
	M4CoffeeMakerAPI();
	M4CoffeeMakerAPI(const M4CoffeeMakerAPI &);
	M4CoffeeMakerAPI& operator=(const M4CoffeeMakerAPI &);
	virtual ~M4CoffeeMakerAPI();

};
