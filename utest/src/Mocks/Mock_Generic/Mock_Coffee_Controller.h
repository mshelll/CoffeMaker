#pragma once
#include "gmock/gmock.h"
#include "Generic/Coffee_Controller.h"


class Mock_Coffee_Controller:public CoffeeController
{
public:
    virtual ~Mock_Coffee_Controller()
    {
    }
    Mock_Coffee_Controller():CoffeeController()
    {
    }

    MOCK_METHOD0(IsHotWaterSourceReady, bool(void));
    MOCK_METHOD0(IsContainmentVesselReady, bool(void));
    MOCK_METHOD0(StartHotWaterSource, void(void));
    MOCK_METHOD0(PauseHotWaterSource, void(void));
    MOCK_METHOD0(ResumeHotWaterSource, void(void));
    MOCK_METHOD0(SignalBrewingComplete, void(void));
};
