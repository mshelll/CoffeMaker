#include "HotWaterSource.h"
#include "Coffee_Controller.h"

static CoffeeController *CoffeeControl;

HotWaterSource::HotWaterSource()
{
	CoffeeControl = new CoffeeController;
}

HotWaterSource::HotWaterSource(CoffeeController *CoffeeController)
{
	CoffeeControl = CoffeeController;
}

HotWaterSource::~HotWaterSource()
{

}

bool HotWaterSource::IsReady()
{
	return true;
}


void HotWaterSource::Start()
{
}

void HotWaterSource::Resume()
{
}

void HotWaterSource::Pause()
{
}

void HotWaterSource::SignalBrewingComplete()
{
	CoffeeControl->SignalBrewingComplete();
}

void HotWaterSource::BrewingComplete()
{

}
