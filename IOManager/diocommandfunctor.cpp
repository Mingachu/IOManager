#include "diocommandfunctor.h"

DIOCommandFunctor::DIOCommandFunctor()
{

}

void DIOCommandFunctor::AddFunction(DIOOperator f)
{
    OperationList.push_back(f);
}

void DIOCommandFunctor::ClearFunction()
{
    OperationList.clear();
}
