#ifndef SIMULATIONIO_H
#define SIMULATIONIO_H
#include "DAQIOBase.h"

using namespace  DAQIO;
class SimulationIO : public DAQIOBase
{
public:
    SimulationIO();
    bool Init();
    bool SetDO(const int &CardNum,const int &index ,const bool &state);
    bool ReadDI(const int &CardNum,const int &index , bool &state);
    bool ReadDO(const int &CardNum,const int &index , bool &state);
    void setSimuPr(const int &DOCount,const int &DICount,const int &CardCount);
    void GetErrorMsg(char* Msg);
    ~SimulationIO();
private :
    int simuDOcount=36;
    int simuDIcount=36;
    int simuCardcount=2;
    vector<bool*> SimuDO;
    vector<bool*> SimuDI;
//    bool SimuDO[16];
//    bool SimuDI[16];

};

#endif // SIMULATIONIO_H
