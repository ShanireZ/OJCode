#include <algorithm>
#include <iostream>
using namespace std;
long long sk[30], n, k, ans;
void dfs(int now, long long res)
{
    if (now > n)
    {
        ans = max(ans, res);
        return;
    }
    dfs(now + 1, res);
    dfs(now + 1, res ^ sk[now]);
}
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        long long c, x, now = 0;
        cin >> c;
        for (int j = 1; j <= c; j++)
        {
            cin >> x;
            now += (1ll << (k - x));
        }
        sk[i] = now;
    }
    dfs(1, 0ll);
    cout << ans << endl;
    return 0;
}