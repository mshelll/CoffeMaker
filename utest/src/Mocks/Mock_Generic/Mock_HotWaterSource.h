#pragma once

#include "gmock/gmock.h"
#include "Generic/HotWaterSource.h"


class Mock_HotWaterSource:public HotWaterSource
{
public:
    virtual ~Mock_HotWaterSource()
    {
    }
    Mock_HotWaterSource():HotWaterSource()
    {
    }

    MOCK_METHOD0(IsReady, bool(void));
    MOCK_METHOD0(Pause, void(void));
    MOCK_METHOD0(Resume, void(void));
    MOCK_METHOD0(Start, void(void));
    MOCK_METHOD0(SignalBrewingComplete, void(void));
    MOCK_METHOD0(BrewingComplete, void(void));

};
