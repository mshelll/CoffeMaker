#include <iostream>

#include "coffeemaker_Main.h"


#include "M4CoffeeMaker/M4HotWaterSource.h"
#include "M4CoffeeMaker/M4ContainmentVessel.h"
#include "M4CoffeeMaker/M4UserInerface.h"

#include "Generic/Coffee_Controller.h"


using namespace std;

coffeemaker_Main::coffeemaker_Main()
{
	cout<<"\n Entered coffeemaker_Main() \n";

	CoffeeControl = new CoffeeController;
}


coffeemaker_Main::~coffeemaker_Main()
{
	cout<<"\n Entered ~coffeemaker_Main() \n";
	delete CoffeeControl;

}


/* This has to be made Genric assignment to M4, M5, M6   Think of a Pattern*/

void coffeemaker_Main::InitializeComponents()
{
	cout <<"\n Entered Initialize Components \n";

	InitializeHotWaterSource();

	InitializeContainmentVessel();

	InitializeUserInterface();

}

void coffeemaker_Main::InitializeHotWaterSource()
{
	cout <<"\n Entered Initialize HotWaterSource \n";
	HotWaterSource *hws = new M4HotWaterSource;
	CoffeeControl->setHotWaterSourceImpl(hws);

}


void coffeemaker_Main::InitializeContainmentVessel()
{
	cout <<"\n Entered Initialize ContainmentVessel \n";
	ContainmentVessel *cv = new M4ContainmentVessel;
	CoffeeControl->setContainmentVesselImpl(cv);

}

void coffeemaker_Main::InitializeUserInterface()
{
	cout <<"\n Entered Initialize UserInterface \n";
	UserInterface *ui = new M4UserInterface;
	CoffeeControl->setUserInterfaceImpl(ui);

}


int main(void)
{
	coffeemaker_Main *coffee = new coffeemaker_Main;

	coffee->InitializeComponents();


	return 0;
}
