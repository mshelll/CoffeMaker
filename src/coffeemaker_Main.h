#pragma once


class CoffeeController;

class coffeemaker_Main {
public:
	coffeemaker_Main();
	virtual ~coffeemaker_Main();

	void InitializeComponents();

	CoffeeController *CoffeeControl;
private:
	void InitializeHotWaterSource();
	void InitializeContainmentVessel();
	void InitializeUserInterface();
};
