#pragma once

class CoffeeController;

class HotWaterSource {
public:
	HotWaterSource();
	HotWaterSource(CoffeeController *CoffeeControl);
	virtual ~HotWaterSource();
	virtual bool IsReady();
	virtual void Pause();
	virtual void Resume();
	virtual void Start();
	virtual void SignalBrewingComplete();
	virtual void BrewingComplete();
};
