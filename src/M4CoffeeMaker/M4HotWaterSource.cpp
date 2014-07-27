#include "M4HotWaterSource.h"
#include "API/M4CoffeeMakerAPI.h"



using namespace HotWaterSourceDefines;


M4HotWaterSource::M4HotWaterSource()
{
  api = M4CoffeeMakerAPI::getInstance();
}


M4HotWaterSource::~M4HotWaterSource()
{
  M4CoffeeMakerAPI::removeInstance();
}

bool M4HotWaterSource::IsReady()
{
	if( api->getBoilerStatus() == BOILER_NOT_EMPTY )
	{
		return true;
	}

	return false;
}


 void M4HotWaterSource::Pause()
{
	api->setReliefValveState(VALVE_OPEN);
	api->setBoilerState(BOILER_OFF);
}

 void M4HotWaterSource::Resume()
{
	api->setReliefValveState(VALVE_CLOSED);
	api->setBoilerState(BOILER_ON);
}


void M4HotWaterSource::Start()
{
	api->setReliefValveState(VALVE_CLOSED);
	api->setBoilerState(BOILER_ON);
}
