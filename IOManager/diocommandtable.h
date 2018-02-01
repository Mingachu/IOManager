#ifndef DIOCOMMANDTABLE_H
#define DIOCOMMANDTABLE_H

#include <string>
#include <vector>
#include <tuple>
using namespace std;

class DIOCommandTable
{
public:
    DIOCommandTable();

    struct CommandTable
    {
        string LabelName;
        vector<int> PrOverrideTable;
        int getPrOverrideCount()
        {
            return (int)PrOverrideTable.size();
        }
    };

};

#endif // DIOCOMMANDTABLE_H
