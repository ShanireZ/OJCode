#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int read();
int tree[100005], p[100005], all[100005], ans[100005], n, sz;
vector<int> son[100005];
int lowbit(int x)
{
    return x & -x;
}
void edit(int now, int x)
{
    while (now <= sz)
    {
        tree[now] += x;
        now += lowbit(now);
    }
}
int query(int now)
{
    int ans = 0;
    while (now)
    {
        ans += tree[now];
        now -= lowbit(now);
    }
    return ans;
}
void dfs(int now)
{
    ans[now] = query(sz) - query(p[now]);
    for (int i = 0; i < son[now].size(); i++)
    {
        int s = son[now][i];
        dfs(s);
    }
    ans[now] = query(sz) - query(p[now]) - ans[now];
    edit(p[now], 1);
}
int main()
{
    n = read();
    for (int i = 1; i <= n; i++)
    {
        all[i] = p[i] = read();
    }
    sort(all + 1, all + 1 + n);
    sz = unique(all + 1, all + 1 + n) - (all + 1);
    for (int i = 1; i <= n; i++)
    {
        p[i] = lower_bound(all + 1, all + 1 + sz, p[i]) - all;
    }
    for (int i = 2; i <= n; i++)
    {
        int fa = read();
        son[fa].push_back(i);
    }
    dfs(1);
    for (int i = 1; i <= n; i++)
    {
        printf("%d\n", ans[i]);
    }
    return 0;
}
int read()
{
    int ans = 0;
    char ch = getchar();
    while (ch > '9' || ch < '0')
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