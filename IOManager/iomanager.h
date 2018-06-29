#ifndef IOMANAGER_H
#define IOMANAGER_H

#if defined(IOManager_LIBRARY)
#  define IOManagerSHARED_EXPORT __declspec(dllexport)
#else
#  define IOManagerSHARED_EXPORT __declspec(dllimport)
#endif

#include "string"
#include "vector"

#ifdef __cplusplus
extern "C" {
#endif
//#include "io_ioc0640.h"
//#include "simulationio.h"
#include "DAQIOBase.h"

namespace DAQIO {

//class DAQIOBase;

class IOManagerSHARED_EXPORT IOManager:public DAQIOBase
{
public:

    IOManager();
    void SetSimuCard(const int &CardNum ,const int &DOCount,const int &DICount );
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
#ifdef __cplusplus
}
}
#endif
#endif // IOMANAGER_H
