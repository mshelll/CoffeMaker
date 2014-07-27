#pragma once
#include "gmock/gmock.h"
#include "Generic/ContainmentVessel.h"


class Mock_ContainmentVessel:public ContainmentVessel
{
public:
    virtual ~Mock_ContainmentVessel()
    {
    }
    Mock_ContainmentVessel():ContainmentVessel()
    {
    }
    MOCK_METHOD0(IsReady, bool(void));
    MOCK_METHOD0(Pause, void(void));
    MOCK_METHOD0(Resume, void(void));
    MOCK_METHOD0(SignalBrewingComplete, void(void));
    MOCK_METHOD0(BrewingComplete, void(void));

};
