#include "M4UserInerface.h"
#include "API/M4CoffeeMakerAPI.h"


using namespace UserInterfaceDefines;



M4UserInterface::M4UserInterface()
{
   api = M4CoffeeMakerAPI::getInstance();
}

M4UserInterface::~M4UserInterface()
{
  M4CoffeeMakerAPI::removeInstance();
}

bool  M4UserInterface::IsBrewButtonPushed()
{
	if( api->getBrewButtonStatus() == BREW_BUTTON_PUSHED )
	{
		 return true;
	}
	else
	{
		return false;
	}
} 

void M4UserInterface::StartBrewing()
{
	if( IsBrewButtonPushed() )
	{
		 UserInterface::StartBrewing();
	}
	
}
