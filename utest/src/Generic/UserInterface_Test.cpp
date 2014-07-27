#include "UserInterface_Test.h"
#include "CoffeeTest_Main.h"

using testing::_;
using testing::ElementsAre;
using testing::Property;
using testing::Matcher;
using testing::Return;
using testing::SetArgPointee;
using testing::Mock;

TEST_F(UserInterface_Test, StartBrewing_Empty_Result)
{
	//EXPECT_CALL(*coffee_control, IsHotWaterSourceReady())
	EXPECT_CALL(*coffee_control, IsHotWaterSourceReady())
			.Times(1)
			.WillOnce(Return(true));
	EXPECT_CALL(*coffee_control, IsContainmentVesselReady())
			.Times(1)
			.WillOnce(Return(true));
	ui->StartBrewing();
}


