#include <algorithm>
#include <iostream>
#include <random>
#include <vector>
using namespace std;
mt19937 rnd(time(0));
vector<int> g[100005];
int sz[100005], T, n, zx1, zx2;
long long r[100005], hsh[100005], tmp[100005], mod = 1e9 + 7, b1, b2;
void dfs1(int now, int from)
{
    sz[now] = 1;
    int ok = 1;
    for (int nxt : g[now])
    {
        if (nxt == from)
        {
            continue;
        }
        dfs1(nxt, now);
        sz[now] += sz[nxt];
        ok = (sz[nxt] > n / 2 ? 0 : ok);
    }
    if (ok && n - sz[now] <= n / 2)
    {
        zx1 == 0 ? zx1 = now : zx2 = now;
    }
}
void dfs2(int now, int from, int dp)
{
    for (int nxt : g[now])
    {
        if (nxt == from)
        {
            continue;
        }
        dfs2(nxt, now, dp + 1);
    }
    int pos = 0;
    for (int nxt : g[now])
    {
        if (nxt == from)
        {
            continue;
        }
        tmp[++pos] = hsh[nxt];
    }
    sort(tmp + 1, tmp + pos + 1);
    hsh[now] = b1 * dp % mod;
    for (int i = 1; i <= pos; i++)
    {
        hsh[now] = hsh[now] * tmp[i] % mod * r[i] % mod;
    }
    hsh[now] = (hsh[now] + b2 * dp % mod) % mod;
}
int main()
{
    for (int i = 1; i <= 100000; i++)
    {
        r[i] = rnd() % mod;
    }
    b1 = rnd() % 233, b2 = rnd() % 277;
    cin >> T;
    while (T--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            sz[i] = 0, g[i].clear();
        }
        for (int i = 1; i < n; i++)
        {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v), g[v].push_back(u);
        }
        zx1 = zx2 = 0;
        dfs1(1, 0);
        dfs2(zx1, 0, 1);
        long long res1 = hsh[zx1];
        if (zx2)
        {
            dfs2(zx2, 0, 1);
            res1 = min(res1, hsh[zx2]);
        }
        for (int i = 1; i <= n; i++)
        {
            sz[i] = 0, g[i].clear();
        }
        for (int i = 1; i < n; i++)
        {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v), g[v].push_back(u);
        }
        zx1 = zx2 = 0;
        dfs1(1, 0);
        dfs2(zx1, 0, 1);
        long long res2 = hsh[zx1];
        if (zx2)
        {
            dfs2(zx2, 0, 1);
            res2 = min(res2, hsh[zx2]);
        }
        cout << (res1 == res2 ? "YES" : "NO") << '\n';
    }
    return 0;
}