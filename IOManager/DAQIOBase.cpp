#include "DAQIOBase.h"

DAQIOBase::DAQIOBase()
{
    _CardCount=0;
    _InitState=false;
}
int DAQIOBase::GetCardProperty(IOCardProperty item, const int &CardNum)
{
    if(CardNum<_CardCount)
    {
        switch (item)
        {
        case IOCardProperty::CardCount:
            return _CardCount;
            //break;
        case IOCardProperty::DICount:
            return _DICount[CardNum];
            //break;
        case IOCardProperty::DOCount:
            return _DOCount[CardNum];
            //break;
        case IOCardProperty::InitState:
            return _InitState? 1:0;
            //break;
        }
    }
    return 0;
}
