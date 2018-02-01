#ifndef DIOCOMMANDBASE_H
#define DIOCOMMANDBASE_H

#include <string>

#include <vector>
#include <iomanager.h>
#include <time.h>
#include "functional"
using namespace std;

//typedef bool (*DIOOperator)(string &msg);
typedef std::function<bool(string &msg)> DIOOperator;
class DIOCommandBase
{
public:
    DIOCommandBase(IOManager *IOPtr);
    virtual bool Complier(vector<string>& StrArray, string &ErrorMsg,DIOOperator &opr)=0;
    string GetCommandName();
    inline static bool isNumber(int c){return '0' <= c && c <= '9';}
protected:
    vector<int*> PrOverride;
    IOManager *_IOPtr;
    enum EnumParemeterType{VInt=0,VFloat=1,VBOOL=2};
    bool ParseINT(string &str , int &value);
    bool ParseFLOAT(string &str , float &value);
    bool ParseBOOL(string &str, bool &value);
    string _LabelName;
    void TImeDelay(const int &msec);
};

#endif // DIOCOMMANDBASE_H
