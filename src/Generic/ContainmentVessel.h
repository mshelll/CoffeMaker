#pragma once

class CoffeeController;

class ContainmentVessel
{
public:
ContainmentVessel();
ContainmentVessel(CoffeeController *CoffeeControl);
virtual ~ContainmentVessel();
virtual bool IsReady();
virtual void Pause();
virtual void Resume();
virtual void SignalBrewingComplete();
virtual void BrewingComplete();

private :

void PauseHotWaterSource();
void ResumeHotWaterSource();
};
