#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
set<long long> res[25];
long long n, m, ans, a[25][25], p[45];
void dfs(int x, int y, long long sum)
{
    sum = (sum * 10 + a[x][y]) % m;
    if (x + y == n + 1)
    {
        res[x].emplace(sum * p[n - 1] % m);
        return;
    }
    dfs(x + 1, y, sum), dfs(x, y + 1, sum);
}
void dfs2(int x, int y, long long sum)
{
    if (x + y == n + 1)
    {
        auto it = res[x].lower_bound(m - sum);
        if (it != res[x].begin())
        {
            ans = max(ans, (sum + *(--it)) % m);
        }
        ans = max(ans, (sum + *(--res[x].end())) % m);
        return;
    }
    sum = (sum + a[x][y] * p[n * 2 - x - y]) % m;
    dfs2(x - 1, y, sum), dfs2(x, y - 1, sum);
}
int main()
{
    cin >> n >> m;
    p[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        p[i] = p[i - 1] * 10 % m;
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    dfs(1, 1, 0);
    dfs2(n, n, 0);
    cout << ans << endl;
    return 0;
}