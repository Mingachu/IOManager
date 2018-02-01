#ifndef DIOCOMMANDFUNCTOR_H
#define DIOCOMMANDFUNCTOR_H
#include <vector>
using namespace std;

typedef bool (*DIOOperator)();
class DIOCommandFunctor
{
public:
    DIOCommandFunctor();
    void AddFunction(DIOOperator f);
    void ClearFunction();
    void Operation();
private:
    vector<DIOOperator> OperationList;

};

#endif // DIOCOMMANDFUNCTOR_H
