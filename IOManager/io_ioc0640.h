#ifndef IO_IOC0640_H
#define IO_IOC0640_H

#include "DAQIOBase.h"
#include "Windows.h"
#include "IOC0640.H"

using namespace std;

using namespace DAQIO;
class IO_IOC0640 : public DAQIOBase
{
public:
    IO_IOC0640();
    bool Init();
    bool SetDO(const int &CardNum,const int &index ,const bool &state);
    bool ReadDI(const int &CardNum,const int &index , bool &state);
    bool ReadDO(const int &CardNum,const int &index , bool &state);
    void GetErrorMsg(char* Msg);
    ~IO_IOC0640();
private :

};

#endif // IO_IOC0640_H
