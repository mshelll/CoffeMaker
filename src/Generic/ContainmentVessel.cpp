#include "ContainmentVessel.h"
#include "Coffee_Controller.h"

static CoffeeController *CoffeeControl;

ContainmentVessel::~ContainmentVessel()
{

}


ContainmentVessel::ContainmentVessel()
{
	CoffeeControl = new CoffeeController;
}

ContainmentVessel::ContainmentVessel(CoffeeController *CoffeeController)
{
	CoffeeControl = CoffeeController;
}

bool ContainmentVessel::IsReady()
{
	return true;
}

void ContainmentVessel::Pause()
{
	PauseHotWaterSource();
}

void ContainmentVessel::PauseHotWaterSource()
{
	CoffeeControl->PauseHotWaterSource();
}

void ContainmentVessel::Resume()
{
	ResumeHotWaterSource();
}

void ContainmentVessel::ResumeHotWaterSource()
{
	CoffeeControl->ResumeHotWaterSource();
}

void ContainmentVessel::SignalBrewingComplete()
{
	CoffeeControl->SignalBrewingComplete();
}
void ContainmentVessel::BrewingComplete()
{

}


