#ifndef SIMULATIONIO_H
#define SIMULATIONIO_H
#include "DAQIOBase.h"

class SimulationIO : public DAQIOBase
{
public:
    SimulationIO();
    bool Init();
    bool SetDO(const int &CardNum,const int &index ,const bool &state);
    bool ReadDI(const int &CardNum,const int &index , bool &state);
    bool ReadDO(const int &CardNum,const int &index , bool &state);
    void GetErrorMsg(char* Msg);
    ~SimulationIO();
private :
    const int simucount=12;
    const int simuCardcount=2;
    vector<bool*> SimuDO;
    vector<bool*> SimuDI;
//    bool SimuDO[16];
//    bool SimuDI[16];

};

#endif // SIMULATIONIO_H
