#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int cnt[100005], k[100005], f[100005], sz[100005], n, m;
vector<int> to[100005];
void dfs(int now)
{
    for (int nxt : to[now])
    {
        if (nxt == f[now])
        {
            continue;
        }
        f[nxt] = now;
        dfs(nxt);
        cnt[now] += cnt[nxt];
        sz[now] += sz[nxt];
    }
    sz[now]++;
    if (k[now])
    {
        cnt[now] = max(cnt[now], (sz[now] + 1) / 2);
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x;
        cin >> x;
        k[x] = 1;
    }
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    dfs(1);
    cout << cnt[1] << endl;
    return 0;
}