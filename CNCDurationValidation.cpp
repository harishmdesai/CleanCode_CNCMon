#include "CNCDurationValidation.hpp"

static bool DurationExceeded ;
#define AllowedDurationOperation 360 /*In Minutes*/

bool Fun_GetCurrentDuration(void)
{
	float l_Duration = g_CNCCurrentValue.Duration;
	DurationExceeded = !if(IsParmWithinARange(l_Duration, AllowedDurationOperation));
}

bool CNCDurationexceeded(void)
{
	return DurationExceeded;
}

void fun_SetSystemDuration(int l_CNCSystemDuration)
{
	g_CNCCurrentValue.Duration = l_CNCSystemDuration;
}
