#include <cstring>
#include <iostream>
using namespace std;
long long mp[205][205], tot[205][205];
int main()
{
    int n, m;
    cin >> n >> m;
    memset(mp, 128, sizeof(mp));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> mp[i][j];
        }
    }
    for (int i = n + 1; i >= 1; i--)
    {
        int st = max(m / 2 - (n - i), 1);
        int ed = min(m / 2 + 2 + (n - i), m);
        for (int j = st; j <= ed; j++)
        {
            tot[i - 1][j - 1] = max(tot[i - 1][j - 1], mp[i - 1][j - 1] + tot[i][j]);
            tot[i - 1][j] = max(tot[i - 1][j], mp[i - 1][j] + tot[i][j]);
            tot[i - 1][j + 1] = max(tot[i - 1][j + 1], mp[i - 1][j + 1] + tot[i][j]);
        }
    }
    long long ans = tot[1][1];
    for (int i = 2; i <= m; i++)
    {
        ans = max(ans, tot[1][i]);
    }
    cout << ans << endl;
    return 0;
}