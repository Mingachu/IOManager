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
    _DOCount.clear();
    _DICount.clear();
    SimuDO.clear();
    SimuDI.clear();
    for (int i=0 ;i<_CardCount ; i++)
    {
        bool *NewDO=new bool[simuDOcount];
        bool *NewDI=new bool[simuDIcount];
        for(int i=0 ; i<simuDOcount ; i++)
        {
            NewDO[i]=false;
        }
        for(int i=0 ; i<simuDIcount ; i++)
        {
            NewDI[i]=false;
        }
        _DOCount.push_back(simuDOcount);
        _DICount.push_back(simuDIcount);
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

void SimulationIO::setSimuPr(const int &DOCount, const int &DICount, const int &CardCount)
{
    simuDIcount=DICount;
    simuDOcount=DOCount;
    simuCardcount=CardCount;
}

void SimulationIO::GetErrorMsg(char *Msg)
{

}
