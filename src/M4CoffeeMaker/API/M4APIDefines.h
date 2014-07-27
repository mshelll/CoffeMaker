#pragma once

namespace ContainmentVesselDefines {
enum WarmerStatus {
	WARMER_EMPTY, POT_EMPTY, POT_NOT_EMPTY
};
enum WarmerState {
	WARMER_ON, WARMER_OFF
};
}

namespace UserInterfaceDefines {
enum IndicatorState {
	INDICATOR_ON, INDICATOR_OFF
};
enum BrewButtonStatus {
	BREW_BUTTON_PUSHED, BREW_BUTTON_NOT_PUSHED
};
}

namespace HotWaterSourceDefines {
enum BoilerStatus {
	BOILER_EMPTY, BOILER_NOT_EMPTY
};
enum BoilerState {
	BOILER_ON, BOILER_OFF
};
enum ValveState {
	VALVE_OPEN, VALVE_CLOSED
};

}

