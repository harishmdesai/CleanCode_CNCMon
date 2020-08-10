#include "CNCDiamValidator.hpp"

static bool DimensionOutOfRange ;
#define AllowedDiamRange 0.05

void Fun_GetCurrentDiam(void)
{
	float l_Diam = g_CNCCurrentValue.Diameter;
	DimensionOutOfRange = !if(IsParmWithinARange(l_Diam, AllowedDiamRange));
}

bool CNCDiamValidator(void)
{
	return DimensionOutOfRange;
}

void fun_SetCurrentDiam(float l_CNCCurrentDiam)
{
	g_CNCCurrentValue.Diameter = l_CNCCurrentDiam;
}
