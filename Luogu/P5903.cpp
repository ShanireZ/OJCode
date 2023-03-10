#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const int N = 5e5 + 7;
int n, q, rt, g[N], d[N], f[N][21], son[N], dep[N], top[N], ans;
vector<int> e[N], u[N], v[N];
int s;
long long Ans;
inline int get(int x)
{
    return x ^= x << 13, x ^= x >> 17, x ^= x << 5, s = x;
}
void dfs(int x)
{
    dep[x] = d[x] = d[f[x][0]] + 1;
    for (auto y : e[x])
    {
        f[y][0] = x;
        for (int i = 0; f[y][i]; i++)
            f[y][i + 1] = f[f[y][i]][i];
        dfs(y);
        if (dep[y] > dep[x])
            dep[x] = dep[y], son[x] = y;
    }
}
void dfs(int x, int p)
{
    top[x] = p;
    if (x == p)
    {
        for (int i = 0, o = x; i <= dep[x] - d[x]; i++)
            u[x].push_back(o), o = f[o][0];
        for (int i = 0, o = x; i <= dep[x] - d[x]; i++)
            v[x].push_back(o), o = son[o];
    }
    if (son[x])
        dfs(son[x], p);
    for (auto y : e[x])
        if (y != son[x])
            dfs(y, y);
}
int ask(int x, int k)
{
    if (!k)
        return x;
    x = f[x][g[k]], k -= 1 << g[k];
    k -= d[x] - d[top[x]], x = top[x];
    return k >= 0 ? u[x][k] : v[x][-k];
}
int main()
{
    cin >> n >> q >> s;
    g[0] = -1;
    for (int i = 1; i <= n; i++)
    {
        cin >> f[i][0];
        e[f[i][0]].push_back(i), g[i] = g[i >> 1] + 1;
    }
    rt = e[0][0], dfs(rt), dfs(rt, rt);
    for (int i = 1, x, k; i <= q; i++)
    {
        x = (get(s) ^ ans) % n + 1;
        k = (get(s) ^ ans) % d[x];
        ans = ask(x, k);
        Ans ^= 1ll * i * ans;
    }
    cout << Ans;
    return 0;
}