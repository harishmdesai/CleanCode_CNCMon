#include "CNCTempValidator.hpp"

static bool TempOutofRange;
#define AllowedTempRange 35 /*In Degree C*/

void fun_SetCurrentTemp(float l_CNCCurrentValue)
{
	g_CNCCurrentValue.tempearature = l_CNCCurrentValue;
}

void Fun_GetCurrentTemp(void)
{
	float l_Temp = g_CNCCurrentValue.tempearature;
	TempOutofRange = !if(IsParmWithinARange(l_Temp, AllowedTempRange));
}

bool CNCTempOutOfRange(void)
{
	return TempOutofRange;
}
