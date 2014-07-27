#pragma once

class CoffeeController;

class UserInterface
{
private :
	virtual bool IsHotWaterSourceReady();
	virtual bool IsContainmentVesselReady();
	virtual void StartHotWaterSource();

public:
	UserInterface();
	UserInterface(CoffeeController *CoffeeControl);
	virtual ~UserInterface();
	virtual void StartBrewing();
	virtual void BrewingComplete();
};
