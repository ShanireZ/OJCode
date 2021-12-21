#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
inline int read()
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
// 将点按照dfs序重整编号,这样一个点的子树编号就连续了
// 将询问离线,预处理每个深度的所有点
// 将询问按深度从大到小排序,树状数组记录当前点在当前深度询问下,是否贡献权值
struct Node
{
    int deep, dfn, fa, sz;
    vector<int> son;
};
Node ns[100005];
int cnt, n, m, tree[100005], ans[100005];
vector<int> all[100005];
void dfs(int now, int dp)
{
    ns[now].sz = 1;
    ns[now].deep = dp;
    ns[now].dfn = ++cnt;
    all[dp].push_back(cnt);
    for (int i = 0; i < ns[now].son.size(); i++)
    {
        int s = ns[now].son[i];
        if (s == ns[now].fa)
        {
            continue;
        }
        ns[s].fa = now;
        dfs(s, dp + 1);
        ns[now].sz += ns[s].sz;
    }
}
struct Quest
{
    int root, deep, id;
    bool operator<(const Quest oth) const
    {
        return deep > oth.deep;
    }
};
Quest qst[100005];
int lowbit(int x)
{
    return x & -x;
}
void edit(int x)
{
    while (x <= n)
    {
        tree[x]++;
        x += lowbit(x);
    }
}
int query(int x)
{
    int ans = 0;
    while (x)
    {
        ans += tree[x];
        x -= lowbit(x);
    }
    return ans;
}
int main()
{
    n = read(), m = read();
    for (int i = 1; i < n; i++)
    {
        int x = read(), y = read();
        ns[x].son.push_back(y);
        ns[y].son.push_back(x);
    }
    dfs(1, 1);
    int line = n + 1;
    cnt = 0;
    for (int i = 1; i <= m; i++)
    {
        int op = read(), x = read();
        if (op == 1)
        {
            line = x;
        }
        else
        {
            qst[++cnt].deep = line;
            qst[cnt].id = cnt;
            qst[cnt].root = x;
        }
    }
    sort(qst + 1, qst + 1 + cnt);
    line = n;
    for (int i = 1; i <= cnt; i++)
    {
        while (line >= qst[i].deep)
        {
            for (int j = 0; j < all[line].size(); j++)
            {
                edit(all[line][j]);
            }
            line--;
        }
        int root = qst[i].root;
        ans[qst[i].id] = query(ns[root].dfn + ns[root].sz - 1) - query(ns[root].dfn - 1);
    }
    for (int i = 1; i <= cnt; i++)
    {
        printf("%d\n", ans[i]);
    }
    return 0;
}