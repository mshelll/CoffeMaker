#pragma once

#include "gmock/gmock.h"
#include "Generic/UserInterface.h"


class Mock_UserInterface:public UserInterface
{
public:
    virtual ~Mock_UserInterface()
    {
    }
    Mock_UserInterface():UserInterface()
    {
    }

    MOCK_METHOD0(IsHotWaterSourceReady, bool(void));
    MOCK_METHOD0(IsContainmentVesselReady, bool(void));
    MOCK_METHOD0(StartHotWaterSource, void(void));

    MOCK_METHOD0(StartBrewing, void(void));
    MOCK_METHOD0(BrewingComplete, void(void));
};
