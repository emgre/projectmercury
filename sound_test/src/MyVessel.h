#ifndef PROJECTMERCURY_MYVESSEL_H
#define PROJECTMERCURY_MYVESSEL_H

#include "orbitersdk.h"
#include "XRSound.h"
#include <memory>

class MyVessel : public VESSEL4
{
public:
    MyVessel(OBJHANDLE obj, int flightmodel);
    virtual ~MyVessel() = default;

    void clbkPostCreation() override;
    int clbkConsumeBufferedKey(DWORD key, bool down, char *kstate) override;

private:
    std::unique_ptr<XRSound> m_xrsound;
};

#endif //PROJECTMERCURY_MYVESSEL_H
