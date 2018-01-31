#include "iomanager.h"


IOManager::IOManager():DAQIOBase()
{
    _DAQIOlist.push_back(new IO_IOC0640);
}

bool IOManager::Init()
{
    //std::vector<DAQIOBase*>::iterator _DAQIter = _DAQIOlist.begin();
    int len=_DAQIOlist.size();
    for(int i=0 ; i<len ; i++)
    {
        DAQIOBase *item=_DAQIOlist[i];
        if(item->Init())
        {
            int count=item->GetCardProperty(IOCardProperty::CardCount);
            for( int j =0 ; j<count ;j++)
            {
                 IOTable newtable;
                 newtable.CardNum=j;
                 newtable.Cardptr=item;
                 //newtable.Dtype=DAQCardType(i);
                 _Cardlist.push_back(newtable);
                 _DOCount.push_back(item->GetCardProperty(IOCardProperty::DOCount,j));
                 _DICount.push_back(item->GetCardProperty(IOCardProperty::DICount,j));
            }
        }
    }
    _CardCount=_Cardlist.size();
    return true;
}
bool IOManager::ReadDI(const int &CardNum, const int &index, bool &state)
{

    if (CardNum<_CardCount)
    {
        IOTable Carditem=_Cardlist[CardNum];
        return Carditem.Cardptr->ReadDI(Carditem.CardNum,index,state);
    }
    return false;
}
bool IOManager::ReadDO(const int &CardNum, const int &index, bool &state)
{
    if (CardNum<_CardCount)
    {
        IOTable Carditem=_Cardlist[CardNum];
        return Carditem.Cardptr->ReadDO(Carditem.CardNum,index,state);
    }
    return false;
}
bool IOManager::SetDO(const int &CardNum, const int &index, const bool &state)
{
    if (CardNum<_CardCount)
    {
        IOTable Carditem=_Cardlist[CardNum];
        return Carditem.Cardptr->SetDO(Carditem.CardNum,index,state);
    }
    return false;
}
void IOManager::GetErrorMsg(char *Msg)
{

}

