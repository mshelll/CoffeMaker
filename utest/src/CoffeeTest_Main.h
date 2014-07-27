#pragma once

#include "gmock/gmock.h"

class CoffeeController;




class CoffeeTest_Main
{
public:
	CoffeeTest_Main();
	virtual ~CoffeeTest_Main();
	void InitializeComponents();
	CoffeeController *CoffeeControl;

private:
	void InitializeHotWaterSource();
	void InitializeContainmentVessel();
	void InitializeUserInterface();

};
