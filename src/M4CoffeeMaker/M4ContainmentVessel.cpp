#include "M4ContainmentVessel.h"
#include "API/M4CoffeeMakerAPI.h"

using namespace ContainmentVesselDefines;
	


M4ContainmentVessel::M4ContainmentVessel()
{
  api = M4CoffeeMakerAPI::getInstance();
}

M4ContainmentVessel::~M4ContainmentVessel()
{
  M4CoffeeMakerAPI::removeInstance();
}


bool M4ContainmentVessel::IsReady()
{
	if( api->getWarmerPlateStatus() == POT_EMPTY )
	{
		return true;
	}

	return false;
}
