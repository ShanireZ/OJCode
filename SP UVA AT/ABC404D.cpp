#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
long long ans = 1e15, c[15];
int n, m, vis[15][105], cnt[105];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
    }
    for (int i = 1; i <= m; i++)
    {
        int k, p;
        cin >> k;
        for (int j = 1; j <= k; j++)
        {
            cin >> p;
            vis[p][i] = 1;
        }
    }
    int lmt = pow(3, n);
    for (int s = 1; s < lmt; s++)
    {
        fill(cnt + 1, cnt + 1 + m, 0);
        long long tmp = s, ok = 1, cost = 0;
        for (int i = 1; i <= n; i++, tmp /= 3)
        {
            int t = tmp % 3;
            cost += c[i] * t;
            for (int j = 1; j <= m; j++)
            {
                cnt[j] += vis[i][j] * t;
            }
        }
        for (int j = 1; j <= m; j++)
        {
            if (cnt[j] < 2)
            {
                ok = 0;
                break;
            }
        }
        if(ok)
        {
            ans = min(ans, cost);
        }
    }
    cout << ans << endl;
    return 0;
}