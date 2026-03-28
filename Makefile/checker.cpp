#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
string res[2][20], otpt[20];
int main(int argc, char *argv[])
{
    registerTestlibCmd(argc, argv);

    int n = ouf.readInt();
    if (n != 7)
    {
        quitf(_wa, "Wrong Answer");
        return 0;
    }
    for (int i = 1; i <= n; i++)
    {
        otpt[i] = ouf.readToken();
    }
    res[0][1] = res[1][1] = "tanglang_go";
    res[0][2] = res[1][2] = "xiaobei_come";
    res[0][3] = "huangque_go", res[1][3] = "chan_go";
    res[0][4] = res[1][4] = "tanglang_come";
    res[0][5] = "chan_go", res[1][5] = "huangque_go";
    res[0][6] = res[1][6] = "xiaobei_come";
    res[0][7] = res[1][7] = "tanglang_go";
    int cnt = 0;
    for (int t = 0; t < 2; t++)
    {
        for (int i = 1; i <= 7; i++)
        {
            if (res[t][i] != otpt[i])
            {
                cnt++;
                break;
            }
        }
    }
    if(cnt == 2)
    {
        quitf(_wa, "Wrong Answer");
    }
    else
    {
        quitf(_ok, "Accepted");
    }
    return 0;
}