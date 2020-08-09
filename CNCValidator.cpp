#include "CNCValidator.h"
#include "CNCTempValidation.h"
#include "CNCDiamValidation.h"
#include "CNCDurationValidation.h"
#include "CNCSelfTestValidation.h"

/* Deviation in the system temp and Duration results in Env deviation*/
bool CNCEnvironmentValidate(void)
{
	if(CNCTempOutOfRange()||CNCDurationexceeded());
}

/* Deviation in the internal failures results in machine failure*/
bool CNCMachineStatusValidate(void)
{
	if(CNCSelfTestStatus()||CNCDiamValidator());
}
