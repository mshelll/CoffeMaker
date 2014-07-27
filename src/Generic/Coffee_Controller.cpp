#include "Coffee_Controller.h"

#include "ContainmentVessel.h"
#include "HotWaterSource.h"
#include "UserInterface.h"


static  HotWaterSource *hws ;
static	ContainmentVessel *cv ;
static	UserInterface *ui ;

CoffeeController::CoffeeController()
{

}


CoffeeController::~CoffeeController()
{

}

void CoffeeController::setHotWaterSourceImpl(HotWaterSource *_hws)
{
  hws = _hws;
}

void CoffeeController::setContainmentVesselImpl(ContainmentVessel *_cv)
{
  cv = _cv;
}

void CoffeeController::setUserInterfaceImpl(UserInterface *_ui)
{
  ui = _ui;
}

bool CoffeeController::IsHotWaterSourceReady()
{
  return hws->IsReady();
}

bool CoffeeController::IsContainmentVesselReady()
{
  return cv->IsReady();
}

void CoffeeController::StartHotWaterSource()
{
	hws->Start();
}

void CoffeeController::PauseHotWaterSource()
{
	hws->Pause();
}

void CoffeeController::ResumeHotWaterSource()
{
	hws->Resume();
}

void CoffeeController::SignalBrewingComplete()
{
	hws->BrewingComplete();
	cv->BrewingComplete();
	ui->BrewingComplete();
}
