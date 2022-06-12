#include <cstring>
#include <iostream>
using namespace std;
int l[1005][1005], up[1005][1005], stk[1005][1005], p[1005];
long long dp[1005][1005];
int main()
{
    int n, m;
    long long cnt = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            char ch;
            cin >> ch;
            if (ch == '*')
            {
                continue;
            }
            l[i][j] = l[i][j - 1] + 1;
            up[i][j] = up[i - 1][j] + 1;

            int x = p[j];
            while (x && l[i][j] <= l[stk[j][x]][j])
            {
                x--;
            }
            stk[j][x + 1] = i;
            p[j] = x + 1;
            
            x = stk[j][x];
            if (i - up[i][j] >= x)
            {
                dp[i][j] += 1ll * up[i][j] * l[i][j];
            }
            else
            {
                dp[i][j] += dp[x][j] + 1ll * (i - x) * l[i][j];
            }
            cnt += dp[i][j];
        }
    }
    cout << cnt << endl;
    return 0;
}