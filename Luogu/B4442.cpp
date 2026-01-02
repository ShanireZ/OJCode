#include <algorithm>
#include <iostream>
using namespace std;
int n, m, ans = 2e9, p[15][15][15], d1[15], d2[15];
int main()
{
    cin >> m >> n;
    for (int t = 1; t <= m; t++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cin >> p[t][i][j];
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> d1[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> d2[i];
    }
    for (int a = 1; a <= n; a++)
    {
        for (int b = 1; b <= n; b++)
        {
            if (a == b)
            {
                continue;
            }
            for (int c = 1; c <= n; c++)
            {
                if (b == c || a == c)
                {
                    continue;
                }
                for (int tab = 1; tab < m; tab++)
                {
                    if (p[tab][a][b] == -1)
                    {
                        continue;
                    }
                    for (int tbc = tab + 1; tbc <= m; tbc++)
                    {
                        if (p[tbc][b][c] == -1)
                        {
                            continue;
                        }
                        int val = d1[a] + d2[c] + p[tab][a][b] + p[tbc][b][c];
                        ans = min(ans, val);
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}