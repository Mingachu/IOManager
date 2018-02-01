#include "commandsetdo.h"


CommandSetDO::CommandSetDO(IOManager *IOPtr):DIOCommandBase(IOPtr)
{
    _LabelName="設置輸出 ";
    PrOverride.push_back(new int[4]{3,VInt,VInt,VBOOL}); //cardnum,ionum , on/offnew int[2]={2,VInt,VBOOL}
    PrOverride.push_back(new int[5]{4,VInt,VInt,VBOOL,VInt}); //cardnum,ionum ,on/off ,time ={3,VInt,VBOOL,VInt}
    _overridecount=(int)PrOverride.size();
}

void CommandSetDO::GetOperationFunction(vector<string>& StrArray,const int &index, DIOOperator &opr)
{
    //std::function<void> d;
    //std::function<bool()> d;
    int cardnum=0;
    int ionum=0;
    bool state=false;
    int time=0;
    switch(index)
    {
    case 0:
        ParseINT(StrArray[0],cardnum);
        ParseINT(StrArray[1],ionum);
        ParseBOOL(StrArray[2],state);
        opr = [this,cardnum ,ionum,state](string &str)->bool
        {
            str.append("override:1 ,");
            str.append(std::to_string(cardnum));
            str.append(std::to_string(ionum));
            str.append(std::to_string(state));
            return SetDO(cardnum,ionum,state);
        };
        break;
    case 1:
        ParseINT(StrArray[0],cardnum);
        ParseINT(StrArray[1],ionum);
        ParseBOOL(StrArray[2],state);
        ParseINT(StrArray[3],time);
        opr = [this,cardnum ,ionum,state,time](string &str)->bool
        {
            str.append("override:2 ,");
            str.append(std::to_string(cardnum));
            str.append(std::to_string(ionum));
            str.append(std::to_string(state));
            str.append(std::to_string(time));
            //return true;
            return SetDO(cardnum,ionum,state,time);
        };
        break ;
    }
    //typedef bool fn_type(void);
    //opr=d.target<fn_type>();
    //opr=bool(*d)();
}
bool CommandSetDO::Complier(vector<string>& StrArray, string &ErrorMsg, DIOOperator &opr)
{
    int prcount=StrArray.size();
    bool ParseState=false;
    bool haveparse=false;
    int overridecount=0;
    for(int i=0 ;i<_overridecount ; i++)
    {
        //ErrorMsg.assign();
        //resstr="找不到多載類型";
        if(prcount==PrOverride[i][0])
        {
            overridecount++;
            int* checktype=PrOverride[i];

            for (int j = 0; j<prcount ;j++)
            {
                switch(checktype[j+1])
                {
                case VInt:
                    int resint;
                    ParseState=ParseINT(StrArray[j],resint);
                    //ErrorMsg=ParseState?string.empty():string("無法被轉型為INT");
                    ErrorMsg.assign(ParseState?" ":"Can't Transfer INT ");
                    break;

                case VBOOL:
                    bool resbool;
                    ParseState=ParseBOOL(StrArray[j],resbool);
                    //ErrorMsg=ParseState?string.empty():string("無法被轉型為BOOL");
                    ErrorMsg.assign(ParseState?" ":"Can't Transfer BOOL ");
                    break;

                case VFloat:
                    float resfloat;
                    ParseState=ParseFLOAT(StrArray[j],resfloat);
                    //ErrorMsg=ParseState?string.empty():string("無法被轉型為FLOAT");
                    ErrorMsg.assign(ParseState?" ":"Can't Transfer FLOAT ");
                    break;
                }
                if(!ParseState)
                {
                    ErrorMsg=StrArray[j]+ErrorMsg;
                    break;
                }
            }
            if(ParseState)
            {
                ErrorMsg.assign("OK ");
                if(haveparse)
                {
                    ErrorMsg.assign("the command is fuzzy ");
                    return false;
                }
                haveparse=true;
                GetOperationFunction(StrArray,i,opr);
            }
        }
    }
    if  (overridecount==0)
    {
        ErrorMsg.assign("Can not Fund Override ");
    }
    return ParseState;
}
bool CommandSetDO::SetDO(const int &num,const int &index, const bool &state, const int &msec)
{
    TImeDelay(msec);
    return SetDO(num,index,state);
}
bool CommandSetDO::SetDO(const int &num,const int &index, const bool &state)
{
    return _IOPtr->SetDO(num,index,state);
}
