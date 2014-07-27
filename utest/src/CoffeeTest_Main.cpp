#include "CoffeeTest_Main.h"

#include "Mocks/Mock_Generic/Mock_Coffee_Controller.h"

#include "Mocks/Mock_Generic/Mock_HotWaterSource.h"
#include "Mocks/Mock_Generic/Mock_ContainmentVessel.h"
#include "Mocks/Mock_Generic/Mock_UserInterface.h"


CoffeeTest_Main::CoffeeTest_Main()
{
	CoffeeControl = new Mock_Coffee_Controller;

}


CoffeeTest_Main::~CoffeeTest_Main()
{
	delete CoffeeControl;

}


void CoffeeTest_Main::InitializeComponents()
{
	InitializeHotWaterSource();

	InitializeContainmentVessel();

	InitializeUserInterface();
}

void CoffeeTest_Main::InitializeHotWaterSource()
{
	HotWaterSource *hws = new Mock_HotWaterSource;
	CoffeeControl->setHotWaterSourceImpl(hws);
}


void CoffeeTest_Main::InitializeContainmentVessel()
{
	ContainmentVessel *cv = new Mock_ContainmentVessel;
	CoffeeControl->setContainmentVesselImpl(cv);
}

void CoffeeTest_Main::InitializeUserInterface()
{
	UserInterface *ui = new Mock_UserInterface;
	CoffeeControl->setUserInterfaceImpl(ui);
}


int main(int argc, char **argv)
{
	CoffeeTest_Main *coffee = new CoffeeTest_Main;

	coffee->InitializeComponents();

	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();

}



