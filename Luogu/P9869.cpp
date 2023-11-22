#include <algorithm>
#include <iostream>
using namespace std;
int g[400009]; // 1~n:初始 n+1~2n:反初始 2n+1~3n:最新 3n+1~4n:反最新 4n+1~4n+3:TFU
int dfn(int x)
{
    return g[x] == x ? x : g[x] = dfn(g[x]);
}
int main()
{
    int C, T, n, m;
    cin >> C >> T;
    while (T--)
    {
        cin >> n >> m;
        for (int i = 1; i <= n * 4; i++)
        {
            g[i] = (i <= n * 2 ? i : i - n * 2);
        }
        g[n * 4 + 1] = n * 4 + 1, g[n * 4 + 2] = n * 4 + 2, g[n * 4 + 3] = n * 4 + 3;
        while (m--)
        {
            char opt;
            int x, y;
            cin >> opt >> x;
            if (opt == '+')
            {
                cin >> y;
                int g1 = dfn(y + n * 2), g2 = dfn(y + n * 3); // 有- x x的情况，需要中转变量
                g[x + n * 2] = g1, g[x + n * 3] = g2;
            }
            else if (opt == '-')
            {
                cin >> y;
                int g1 = dfn(y + n * 2), g2 = dfn(y + n * 3);
                g[x + n * 2] = g2, g[x + n * 3] = g1;
            }
            else if (opt == 'T')
            {
                g[x + n * 2] = n * 4 + 1, g[x + n * 3] = n * 4 + 2;
            }
            else if (opt == 'F')
            {
                g[x + n * 2] = n * 4 + 2, g[x + n * 3] = n * 4 + 1;
            }
            else
            {
                g[x + n * 2] = g[x + n * 3] = n * 4 + 3;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            g[i] = dfn(i + n * 2), g[i + n] = dfn(i + n * 3);
        }
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            ans += (dfn(i) == dfn(i + n));
        }
        cout << ans << endl;
    }
    return 0;
}