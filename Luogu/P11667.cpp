#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
int T, n, a, b, s[1005][1005], r1[1005][1005];
int main()
{
    cin >> T;
    while (T--)
    {
        cin >> n >> a >> b;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                char ch;
                cin >> ch;
                s[i][j] = r1[i][j] = 0;
                if (ch == 'G')
                {
                    s[i][j] = 1;
                }
                else if (ch == 'B')
                {
                    s[i][j] = 2;
                }
            }
        }
        int ok = 1, res = 0;
        for (int i = 1; i <= n && ok; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (s[i][j] == 2)
                {
                    int x = i - b, y = j - a;
                    if (x < 1 || y < 1 || s[x][y] == 0)
                    {
                        ok = 0;
                        break;
                    }
                    res += (r1[x][y] == 0);
                    r1[x][y] = 1;
                    res += (r1[i][j] == 0);
                    r1[i][j] = 1;
                }
            }
        }
        for (int i = 1; i <= n && ok; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (s[i][j] == 1 && r1[i][j] == 0)
                {
                    int x = i - b, y = j - a;
                    if (x < 1 || y < 1 || r1[x][y] == 0)
                    {
                        res += (r1[i][j] == 0);
                        r1[i][j] = 1;
                    }
                }
            }
        }
        cout << (ok ? res : -1) << endl;
    }
    return 0;
}