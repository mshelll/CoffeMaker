#pragma once

#include "Generic/HotWaterSource.h"

class M4CoffeeMakerAPI;

class M4HotWaterSource:public HotWaterSource
{

public:
	M4HotWaterSource();
	virtual ~M4HotWaterSource();

	bool IsReady(); 
	void Pause();
	void Resume();
	void Start();

private :
	M4CoffeeMakerAPI *api;
};
