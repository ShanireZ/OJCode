#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string isName[4617];
string numLabel[10];
int num[12];
int pos = 0;

int Check(int numPos, int namePos)
{
    if (numPos == pos)
    {
        return 1;
    }
    if (numLabel[num[numPos]][0] == isName[namePos][numPos] || numLabel[num[numPos]][1] == isName[namePos][numPos] || numLabel[num[numPos]][2] == isName[namePos][numPos])
    {
        int trig = Check(numPos + 1, namePos);
        return trig;
    }
    else
    {
        return 0;
    }
}

int main()
{
    numLabel[2] = "ABC", numLabel[3] = "DEF", numLabel[4] = "GHI", numLabel[5] = "JKL";
    numLabel[6] = "MNO", numLabel[7] = "PRS", numLabel[8] = "TUV", numLabel[9] = "WXY";
    string tmp;
    cin >> tmp;
    pos = tmp.size();
    for (int i = 0; i < tmp.size(); i++)
    {
        num[i] = tmp[i] - '0';
    }
    for (int i = 0; i < 4617; i++)
    {
        cin >> isName[i];
    }

    int none = 1;
    for (int i = 0; i < 4617; i++) //对应姓名表
    {
        if (tmp.size() != isName[i].size())
        {
            continue;
        }
        int trig = Check(0, i);
        if (trig)
        {
            cout << isName[i] << endl;
            none = 0;
        }
    }
    if (none)
    {
        cout << "NONE";
    }
    return 0;
}