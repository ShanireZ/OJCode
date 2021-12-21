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
// 10 10
// 1 2
// 1 3
// 2 4
// 2 5
// 2 6
// 5 8
// 3 7
// 7 9
// 7 10
// 1 2
// 2 2
// 2 7
// 2 8
// 1 4
// 2 3
// 2 5
// 1 3
// 2 10
// 2 6
// 问题离线存入点中,树状数组维护当前每个深度点的个数
// 当前点子树处理完时的状态 - 当前点子树处理前的状态 = 当前点子树的信息
// 用的树上差分的思路,其实也可以主席树,不过杀鸡用牛刀了
int n, m, cnt, pos, tree[100005], qdp[100005], ans[100005];
struct Node
{
    int fa;
    vector<int> son;
    vector<int> qid;
};
Node ns[100005];
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
void dfs(int now, int deep)
{
    for (int i = 0; i < ns[now].qid.size(); i++)
    {
        int id = ns[now].qid[i];
        int dp = qdp[id];
        ans[id] = query(n) - query(dp - 1);
    }
    for (int i = 0; i < ns[now].son.size(); i++)
    {
        int s = ns[now].son[i];
        if (s == ns[now].fa)
        {
            continue;
        }
        ns[s].fa = now;
        dfs(s, deep + 1);
    }
    edit(deep);
    for (int i = 0; i < ns[now].qid.size(); i++)
    {
        int id = ns[now].qid[i];
        int dp = qdp[id];
        ans[id] = query(n) - query(dp - 1) - ans[id];
    }
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
    int dp = n + 1;
    for (int i = 1; i <= m; i++)
    {
        int op = read(), x = read();
        if (op == 1)
        {
            dp = x;
        }
        else
        {
            ns[x].qid.push_back(++cnt);
            qdp[cnt] = dp;
        }
    }
    dfs(1, 1);
    for (int i = 1; i <= cnt; i++)
    {
        printf("%d\n", ans[i]);
    }
    return 0;
}