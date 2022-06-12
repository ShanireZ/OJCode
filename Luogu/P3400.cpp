#include <iostream>
using namespace std;
int lt[3005], up[3005], s[3005];
long long dp[3005], cnt;
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int p = 0;
        for (int j = 1; j <= m; j++)
        {
            int v;
            cin >> v;
            if (v == 0)
            {
                lt[j] = up[j] = 0;
                continue;
            }
            lt[j] = lt[j - 1] + 1;
            up[j] = up[j] + 1;
            while (p && up[s[p]] >= up[j])
            {
                p--;
            }
            int x = s[p];
            s[++p] = j;
            if (j - lt[j] >= x)
            {
                dp[j] = up[j] * lt[j];
            }
            else
            {
                dp[j] = dp[x] + up[j] * (j - x);
            }
            cnt += dp[j];
        }
    }
    cout << cnt << endl;
    return 0;
}