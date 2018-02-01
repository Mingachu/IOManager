#ifndef IOMANAGER_H
#define IOMANAGER_H


#include "DAQIOBase.h"
#include "io_ioc0640.h"
#include "simulationio.h"

class IOManager:public DAQIOBase
{
public:

    IOManager();
    bool Init();
    bool SetDO(const int &CardNum, const int &index, const bool &state);
    bool ReadDI(const int &CardNum, const int &index, bool &state);
    bool ReadDO(const int &CardNum, const int &index, bool &state);
    void GetErrorMsg(char* Msg);
    vector<std::string> GetCardName();
    //enum DAQCardType{IOC0640=0,VRobot=1};
private:
    struct IOTable
    {
        //DAQCardType Dtype;
        DAQIOBase* Cardptr;
        int CardNum;
    };
    vector<DAQIOBase*> _DAQIOlist;
    vector<IOTable> _Cardlist;
};

#endif // IOMANAGER_H
