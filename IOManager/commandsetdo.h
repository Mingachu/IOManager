#ifndef COMMANDSETDO_H
#define COMMANDSETDO_H

#include "diocommandbase.h"

class CommandSetDO:public DIOCommandBase
{
public:
    CommandSetDO(IOManager *IOPtr );
    bool Complier(vector<string>& StrArray, string &ErrorMsg,DIOOperator &opr);
private:
    int _overridecount;

    void GetOperationFunction(vector<string>& StrArray,const int &index,DIOOperator &opr);

    bool SetDO(const int &num , const int &index, const bool &state , const int &msec);
    bool SetDO(const int &num ,const int &index,const bool &state);
};

#endif // COMMANDSETDO_H
