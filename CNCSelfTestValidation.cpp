#include "CNCSelfTestValidation.hpp"

static bool CNCSelfTestFailed ;

// Defining Default values
#define SelfTestStatusCode_AllOk 0xFF
#define SelfTestStatusCode_NoData 0x00
#define SelfTestStatusCode_ControllerBoardNotOk 0x01
#define SelfTestStatusCode_ConfigDataCorrupted 0x02 


void Fun_GetCurrentTemp(void)
{
	g_CNCCurrentValue l_Status = g_CNCCurrentValue.Selfteststatus;
	CNCSelfTestFailed = if(l_Status != SelfTestStatusCode_AllOk);
}

bool CNCSelfTestStatus(void)
{
	return CNCSelfTestFailed;
}
