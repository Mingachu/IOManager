#ifndef DAQIOBase_H
#define DAQIOBase_H

//#include "iostream"
#include "vector"
using namespace std;

namespace DAQIO {

enum class IOCardProperty{CardCount=0,DOCount=1,DICount=2,InitState=3};
class DAQIOBase
{
public:
    DAQIOBase();

    virtual bool Init()=0;
    virtual bool SetDO(const int &CardNum,const int &index ,const bool &state)=0;
    virtual bool ReadDI(const int &CardNum,const int &index , bool &state)=0;
    virtual bool ReadDO(const int &CardNum,const int &index , bool &state)=0;
    int GetCardProperty(IOCardProperty item,const int &CardNum=0);

    void GetCardName(string &name);
    virtual void GetErrorMsg(char* Msg)=0;
protected :

    vector<int> _DOCount;
    vector<int> _DICount;
    //vector<int> _DOCount
    //int _DOCount;
    //int _DICount;
    //int _CardIndex;
    int _CardCount;
    bool _InitState;
    string _CardName;


};
}
#endif // DAQIOBase_H
