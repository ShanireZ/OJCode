#include <algorithm>
#include <iostream>
using namespace std;
int mp[1005][1005], ca[1005], cb[1005], h[1005];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            char ch;
            cin >> ch;
            if (ch == 'H')
            {
                h[i] = 1, mp[i][j] = 3;
            }
            else if (ch == 'A')
            {
                ca[i]++;
            }
            else if (ch == 'B')
            {
                cb[i]++;
            }
        }
        if (h[i] == 0)
        {
            if (ca[i] > cb[i])
            {
                for (int j = m; j >= m - ca[i] + 1; j--)
                {
                    mp[i][j] = 1;
                }
            }
            else if (cb[i] > ca[i])
            {
                for (int j = 1; j <= cb[i]; j++)
                {
                    mp[i][j] = 2;
                }
            }
        }
        else
        {
            for (int j = 1; j <= ca[i]; j++)
            {
                mp[i][j] = 1;
            }
            for (int j = m; j >= m - cb[i] + 1; j--)
            {
                mp[i][j] = 2;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (mp[i][j] == 1 || mp[i][j] == 2)
            {
                if (mp[i][j] == mp[i - 1][j] || mp[i][j] == mp[i + 1][j])
                {
                    cout << '#';
                }
                else
                {
                    cout << char(mp[i][j] + 'A' - 1);
                }
            }
            else if (mp[i][j] == 0)
            {
                cout << '#';
            }
            else
            {
                cout << 'H';
            }
        }
        cout << endl;
    }
    return 0;
}