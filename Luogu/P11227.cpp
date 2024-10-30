#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
string str, cd = "A23456789TJQK", opt = "DCHS";
int n, res = 52, vis[5][15];
int main()
{
    cin >> n;
    while (n--)
    {
        cin >> str;
        int op = 0, pos = 0;
        for (int i = 0; i < 4; i++)
        {
            if (opt[i] == str[0])
            {
                op = i;
                break;
            }
        }
        for (int i = 0; i < 13; i++)
        {
            if (cd[i] == str[1])
            {
                pos = i;
                break;
            }
        }
        if (vis[op][pos] == 0)
        {
            vis[op][pos] = 1, res--;
        }
    }
    cout << res << endl;
    return 0;
}