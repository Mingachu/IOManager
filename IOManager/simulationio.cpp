#include "simulationio.h"

SimulationIO::SimulationIO() :DAQIOBase()
{
    _CardName="SimulationIO";
//    _DOCount.push_back(simucount);
//    _DICount.push_back(simucount);
    _CardCount=simuCardcount;
}

bool SimulationIO::Init()
{
    for (int i=0 ;i<_CardCount ; i++)
    {
        bool *NewDO=new bool[simucount];
        bool *NewDI=new bool[simucount];
        for(int i=0 ; i<simucount ; i++)
        {
            NewDO[i]=false;
            NewDI[i]=false;
        }
        _DOCount.push_back(simucount);
        _DICount.push_back(simucount);
        SimuDO.push_back(NewDO);
        SimuDI.push_back(NewDI);
    }
    _InitState=true;
    return true;
}

bool SimulationIO::SetDO(const int &CardNum, const int &index, const bool &state)
{

    SimuDO[CardNum][index]=state;

    return true ;
}

bool SimulationIO::ReadDI(const int &CardNum, const int &index, bool &state)
{
    state=SimuDI[CardNum][index];
    return true ;
}

bool SimulationIO::ReadDO(const int &CardNum, const int &index, bool &state)
{
    state=SimuDO[CardNum][index];
    return true ;
}

void SimulationIO::GetErrorMsg(char *Msg)
{

}
