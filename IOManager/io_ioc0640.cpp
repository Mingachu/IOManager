#include "io_ioc0640.h"


IO_IOC0640::IO_IOC0640():DAQIOBase()
{
    _CardName="IOC0640";
}

bool IO_IOC0640::Init()
{
    int nCard=0;
    nCard= ioc_board_init();
    //ioc_check_sn()
    _CardCount=nCard;
    if (nCard > 0)
    {
        _InitState = true;
        for (int i=0 ;i<nCard ; i++)
        {
            _DOCount.push_back(16);
            _DICount.push_back(16);
        }
    }
    else
    {
        _InitState = false;
    }
    return _InitState;
}
bool IO_IOC0640::ReadDI(const int &CardNum, const int &index, bool &state)
{
    if(_CardCount<CardNum)
    {
        USHORT _cardnum=CardNum;
        USHORT bitno=index+1;
        int DI=ioc_read_inbit(_cardnum,bitno);
        state = DI == 0 ? true : false;
        return true;
    }
    return false;
}
bool IO_IOC0640::ReadDO(const int &CardNum, const int &index, bool &state)
{
    if(_CardCount<CardNum)
    {
        USHORT _cardnum=CardNum;
        USHORT bitno=index+1;
        int DO=ioc_read_outbit(0,bitno);
        state = DO == 0 ? true : false;
        return true;
    }
    return false;
}
bool IO_IOC0640::SetDO(const int &CardNum, const int &index, const bool &state)
{
    if(_CardCount<CardNum)
    {
        USHORT _cardnum=CardNum;
        USHORT bitno=index+1;
        USHORT DOState = state ? 0 : 1;
        ioc_write_outbit(_cardnum,bitno,DOState);
        return true;
    }
    return false;
}
void IO_IOC0640::GetErrorMsg(char* Msg)
{
    //Msg="Test1";
    sprintf(Msg, "Test");
}

IO_IOC0640::~IO_IOC0640()
{
    ioc_board_close();
}
