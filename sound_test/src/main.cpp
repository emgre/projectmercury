#define ORBITER_MODULE
#include "orbitersdk.h"
#include "MyVessel.h"

DLLCLBK void InitModule(HINSTANCE module)
{

}

DLLCLBK void ExitModule(HINSTANCE module)
{

}

DLLCLBK VESSEL* ovcInit(OBJHANDLE vessel, int flightmodel)
{
    return new MyVessel(vessel, flightmodel);
}

DLLCLBK void ovcExit(VESSEL* vessel)
{
    if(vessel)
    {
        // A cast is needed here because VESSEL does not have a virtual destructor
        delete static_cast<MyVessel*>(vessel);
    }
}
