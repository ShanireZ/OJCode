#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
int m[2005][2005];
int cube[3][4];
int main()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> cube[i][j];
        }
    }
    for (int i = cube[2][0] + 1000; i < cube[2][2] + 1000; i++)
    {
        for (int j = cube[2][1] + 1000; j < cube[2][3] + 1000; j++)
        {
            m[i][j] = 1;
        }
    }
    int tot = 0;
    for (int t = 0; t < 2; t++)
    {
        for (int i = cube[t][0] + 1000; i < cube[t][2] + 1000; i++)
        {
            for (int j = cube[t][1] + 1000; j < cube[t][3] + 1000; j++)
            {
                if (m[i][j] == 0)
                {
                    tot++;
                }
            }
        }
    }
    cout << tot;
    return 0;
}