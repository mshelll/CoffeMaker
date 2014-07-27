#pragma once


#include "gmock/gmock.h"


#include "Generic/UserInterface.h"

#include "Mocks/Mock_Generic/Mock_HotWaterSource.h"
#include "Mocks/Mock_Generic/Mock_ContainmentVessel.h"
#include "Mocks/Mock_Generic/Mock_Coffee_Controller.h"

class UserInterface_Test:public testing::Test
{
public:
	UserInterface_Test()
	{

	}

	void SetUp()
	{
		hws =  new Mock_HotWaterSource;
		cv  =  new Mock_ContainmentVessel;
		coffee_control = new Mock_Coffee_Controller;
		ui  =  new UserInterface(coffee_control);

	}

	void TearDown()
	{
		delete hws;
		delete cv;
		delete coffee_control;
		delete ui;

	}

	~UserInterface_Test()
	{

	}

	Mock_HotWaterSource *hws;
	Mock_ContainmentVessel *cv;
	UserInterface *ui;
	Mock_Coffee_Controller *coffee_control;
};





