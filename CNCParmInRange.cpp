#include "CNCParmInRange.hpp"

bool IsParmInRange(float arg1,float arg2)
{
   bool l_return = FALSE;
   if(arg1 < arg2)
   {
      l_return = TRUE;
   }
   
   return l_return;
}


#endif
