#include <algorithm>
#include <iostream>
using namespace std;
int mp[105][105];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            char ch;
            cin >> ch;
            mp[i][j] = ch - '0';
        }
    }
    int t = 0;
    for (int i = 1; i <= n; i++)
    {
        int x = n + 1, y = i, ok = 1;
        while (true)
        {
            if (mp[x - 1][y] == 1 && mp[x][y - 1] == 1)
            {
                ok = 0;
                break;
            }
            else if (mp[x - 1][y] == 1)
            {
                y--;
            }
            else
            {
                x--;
            }
            if (y == 0 || x == 0)
            {
                break;
            }
        }
        if (ok == 0)
        {
            if (t != 0)
            {
                cout << " ";
            }
            t = 1;
            cout << i;
        }
    }
    return 0;
}