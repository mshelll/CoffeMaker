#include "M4CoffeeMakerAPI.h"
#define NULL (void * )0
#define null (M4CoffeeMakerAPI *)NULL

unsigned int M4CoffeeMakerAPI::ReferenceCount = 0;
M4CoffeeMakerAPI * M4CoffeeMakerAPI::instance = null;

M4CoffeeMakerAPI::M4CoffeeMakerAPI() {

}

M4CoffeeMakerAPI::~M4CoffeeMakerAPI() {

}

M4CoffeeMakerAPI * M4CoffeeMakerAPI::getInstance() {
	if (instance == null && ReferenceCount == 0) {
		instance = new M4CoffeeMakerAPI;
	}
	ReferenceCount++;
	return instance;

}

void M4CoffeeMakerAPI::removeInstance() {
	ReferenceCount--;
	if (instance != null && ReferenceCount == 0) {
		delete instance;
		instance = null;
	}
}

M4CoffeeMakerAPI::M4CoffeeMakerAPI(const M4CoffeeMakerAPI &) {

}

M4CoffeeMakerAPI& M4CoffeeMakerAPI::operator=(const M4CoffeeMakerAPI &) {
	return *this;
}

int M4CoffeeMakerAPI::getBoilerStatus() {
	return BoilerStatus;
}

int M4CoffeeMakerAPI::getBrewButtonStatus() {
	return BrewButtonStatus;
}

int M4CoffeeMakerAPI::getWarmerPlateStatus() {
	return WarmerPlateStatus;
}

void M4CoffeeMakerAPI::setBoilerState(int BoilerState) {
	BoilerStatus = BoilerState;
}

void M4CoffeeMakerAPI::setWarmerState(int warmerState) {
	WarmerPlateStatus = warmerState;
}
void M4CoffeeMakerAPI::setIndicatorState(int indicatorState) {

}

void M4CoffeeMakerAPI::setReliefValveState(int reliefValveState) {

}
