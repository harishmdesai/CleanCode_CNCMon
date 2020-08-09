#include "CNCValidator.hpp"
#include "CNCSelfTestValidation.hpp"
#include "CNCTempValidator.hpp"
#include "CNCDurationValidation.hpp"
#include "CNCDiamValidator.hpp"

typedef enum 
{
	CNC_SelfTest = 0;
	CNC_TempMon,
	CNC_DiamVariation,
	CNC_DurationOfOper,
	CNC_NoOfMon
}CNC_ListOfMOn;

typedef enum
{
	CNCSelfTestAllOK,
	CNCSelfTestNoData,
	CNCSelfTestContBoard,
	CNCSelfTestConfigData
}CNC_SelfTestStatus;

typedef struct 
{
	CNC_SelfTestStatus Selfteststatus;
	float tempearature;
	float Diameter;
	float Duration;
} CNC_CurrentValue;

static bool CNCSWInit = TRUE;
#define IsParmWithinARange(Value, Reference) (Value<Reference)

static fun_SoftwareInit()
{
	g_CNCCurrentValue.Selfteststatus = CNCSelfTestAllOK;
	g_CNCCurrentValue.tempearature = 26;
	g_CNCCurrentValue.Diameter = 0.20;
	g_CNCCurrentValue.Duration = 20;
}

typedef enum
{
    CNC_MachineAllOk,
    CNC_MachineFailure,
    CNC_EnvironmentFailure,
    CNC_EnvironmentNMachineFailure
}CNC_DiagStatus;

int main ()
{
	 bool IsEnvironmentFailed, IsMachineFailed;
	/*SW Initialization*/
	if(CNCSWInit)
	{
		fun_SoftwareInit();
		/*SW Initialization DOne*/
		CNCSWInit = FALSE;
	}
	/*Get the Mon data cyclically*/
	
	
	/*Get the status*/
    IsEnvironmentFailed = CNCEnvironmentValidate();
    IsMachineFailed = CNCMachineStatusValidate();

	/*Validator*/
    if(IsEnvironmentFailed && IsMachineFailed)
    {
        return(CNC_EnvironmentNMachineFailure);
    }
    else if (IsEnvironmentFailed)
    {
        return(CNC_EnvironmentFailure);
    }
    else if (IsMachineFailed)
    {
        return(CNC_MachineFailure);
    }
    else
    {
        return(CNC_MachineAllOk);
    }   
}
