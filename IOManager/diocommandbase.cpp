#include "diocommandbase.h"
DIOCommandBase::DIOCommandBase(IOManager *IOPtr)
{
    //LabelName=name;
    //IOPtr=IOPtr;
    _IOPtr=IOPtr;
}

string DIOCommandBase::GetCommandName()
{
    return _LabelName;
}
bool DIOCommandBase::ParseINT(string &str, int &value)
{
    //std::string myWord = "myWord";
    int strlength=str.size()+1;
    char* ParseArray=new char[strlength];
    strcpy(ParseArray, str.c_str());
    bool res=true;
    for(int i=0 ; i<strlength-1 ; i++)
    {
        if(!isNumber(ParseArray[i]))
        {
            res=false;
            break;
        }
    }
    if(res)
    {
        value= stoi(str);
    }
    delete[] ParseArray;
    return res;
}
bool DIOCommandBase::ParseFLOAT(string &str, float &value)
{
    int strlength=str.size()+1;
    char* ParseArray=new char[strlength];
    strcpy(ParseArray, str.c_str());
    bool res=true;
    bool havedot=false;
    if(ParseArray[0]=='.')
    {
        return false;
    }
    for(int i=1 ; i<strlength-1 ; i++)
    {
        if(!isNumber(ParseArray[i])&&ParseArray[i]!='.')
        {
            res=false;
            break;
        }
        else if(ParseArray[i]=='.')
        {
            res=!havedot;
            havedot=true;
        }
    }
    if(res)
    {
        value=stof(str);
    }
    delete[] ParseArray;
    return res;
}
bool DIOCommandBase::ParseBOOL(string &str, bool &value)
{
    if(str=="ON")
    {
        value=true;
        return true;
    }
    if(str=="OFF")
    {
        value=false;
        return true;
    }
    return false;
}
void DIOCommandBase::TImeDelay(const int &msec)
{
   Sleep(msec);
//    unsigned int retTime = time(0) + msec;
//    while (time(0) < retTime);
}
