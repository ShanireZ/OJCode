#include <iostream>
using namespace std;
int n, m, g[105][105];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        g[i][i] = 1;
    }
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a][b] = 1;
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (g[i][k] == 1 && g[k][j] == 1)
                {
                    g[i][j] = 1;
                }
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int trig = 1;
        for (int j = 1; j <= n; j++)
        {
            if (g[i][j] == 0 && g[j][i] == 0)
            {
                trig = 0;
                break;
            }
        }
        ans += trig;
    }
    cout << ans;
    return 0;
}