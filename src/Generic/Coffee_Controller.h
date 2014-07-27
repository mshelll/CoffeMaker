#pragma once

class HotWaterSource;
class UserInterface;
class ContainmentVessel;

class CoffeeController
{

public:
	CoffeeController();
	virtual ~CoffeeController();

	void setHotWaterSourceImpl(HotWaterSource *hws);
	void setContainmentVesselImpl(ContainmentVessel *cv);
	void setUserInterfaceImpl(UserInterface *ui);

	virtual bool IsHotWaterSourceReady();
	virtual bool IsContainmentVesselReady();
	virtual void StartHotWaterSource();
	virtual void PauseHotWaterSource();
	virtual void ResumeHotWaterSource();
	virtual void SignalBrewingComplete();
	

};
