#include "UserInterface.h"
#include "Coffee_Controller.h"

static CoffeeController *CoffeeControl;

UserInterface::~UserInterface()
{

}

UserInterface::UserInterface()
{
	CoffeeControl = new CoffeeController;
}

UserInterface::UserInterface(CoffeeController *CoffeeController)
{
	CoffeeControl = CoffeeController;
}

void UserInterface::StartBrewing()
{
	if( IsHotWaterSourceReady() && IsContainmentVesselReady() )
	{
		 StartHotWaterSource();
	}
	
}

bool UserInterface::IsHotWaterSourceReady()
{
	return CoffeeControl->IsHotWaterSourceReady();
}

bool UserInterface::IsContainmentVesselReady()
{
	return CoffeeControl->IsContainmentVesselReady();
}

void UserInterface::StartHotWaterSource()
{
	CoffeeControl->StartHotWaterSource();
}

void UserInterface::BrewingComplete()
{

}
