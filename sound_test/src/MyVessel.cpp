#include "MyVessel.h"

MyVessel::MyVessel(OBJHANDLE obj, int flightmodel)
        : VESSEL4(obj, flightmodel)
{

}

void MyVessel::clbkPostCreation()
{
    m_xrsound = std::unique_ptr<XRSound>(XRSound::CreateInstance(this));
}

int MyVessel::clbkConsumeBufferedKey(DWORD key, bool down, char *kstate)
{
    if(key == OAPI_KEY_P && down)
    {
        if(!m_xrsound->IsWavPlaying(1))
        {
            m_xrsound->LoadWav(1, "XRSound/SoundTest/test.mp3", XRSound::Global);
            m_xrsound->PlayWav(1);
        }
        else
        {
            m_xrsound->StopWav(1);
        }
        
        return 1;
    }
    
    return 0;
}
