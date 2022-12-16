#include <iostream>
using namespace std;
#define MX 200005
int anc[MX][20], eid[MX], dp[MX], last[MX], to[MX * 2], pre[MX * 2], pos, read();
long long cnt[MX], c1[MX * 2], c2[MX * 2];
void addEdge(int u, int v, int w1, int w2, int id)
{
    pre[id] = last[u], to[id] = v, c1[id] = w1, c2[id] = w2;
    last[u] = id;
}
void dfs(int now, int deep)
{
    dp[now] = deep;
    for (int i = 1; i <= 18; i++)
    {
        anc[now][i] = anc[anc[now][i - 1]][i - 1];
    }
    for (int i = last[now]; i; i = pre[i])
    {
        int nxt = to[i];
        if (nxt != anc[now][0])
        {
            anc[nxt][0] = now, eid[nxt] = i;
            dfs(nxt, deep + 1);
        }
    }
}
int lca(int a, int b)
{
    if (dp[a] < dp[b])
    {
        swap(a, b);
    }
    for (int i = 18; i >= 0; i--)
    {
        if (dp[anc[a][i]] >= dp[b])
        {
            a = anc[a][i];
        }
    }
    if (a == b)
    {
        return a;
    }
    for (int i = 18; i >= 0; i--)
    {
        if (anc[a][i] != anc[b][i])
        {
            a = anc[a][i], b = anc[b][i];
        }
    }
    return anc[a][0];
}
long long dfs2(int now)
{
    long long ans = 0;
    for (int i = last[now]; i; i = pre[i])
    {
        int nxt = to[i];
        if (nxt != anc[now][0])
        {
            ans += dfs2(nxt);
            cnt[now] += cnt[nxt];
        }
    }
    return ans + min(c2[eid[now]], c1[eid[now]] * cnt[now]);
}
int main()
{
    int n = read();
    for (int i = 1; i < n; i++)
    {
        int a = read(), b = read(), w1 = read(), w2 = read();
        addEdge(a, b, w1, w2, ++pos), addEdge(b, a, w1, w2, ++pos);
    }
    dfs(1, 1);
    for (int i = 1; i < n; i++)
    {
        cnt[lca(i, i + 1)] -= 2;
        cnt[i]++, cnt[i + 1]++;
    }
    printf("%lld\n", dfs2(1));
    return 0;
}
int read()
{
    int ans = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        ans = ans * 10 + ch - '0';
        ch = getchar();
    }
    return ans;
}