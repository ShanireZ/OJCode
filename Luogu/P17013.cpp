#include <algorithm>
#include <iostream>
using namespace std;
int n, ans, lc[100005], rc[100005], f[100005], sz[100005];
void dfs(int now)
{
    if (now == 0)
    {
        return;
    }
    dfs(lc[now]), dfs(rc[now]);
    sz[now] = 1 + sz[lc[now]] + sz[rc[now]];
    f[now] = ((f[lc[now]] && f[rc[now]] && sz[lc[now]] == sz[rc[now]]) || (lc[now] == 0 && rc[now] == 0));
    ans += f[now];
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> lc[i] >> rc[i];
    }
    dfs(1);
    cout << ans << endl;
    return 0;
}