#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct WT
{
    int dp, ans;
};
WT wts[100005];
int n, m, pos, cnt[100005];
vector<int> to[100005], wt[100005];
int lowbit(int x)
{
    return x & -x;
}
void edit(int x)
{
    while (x <= n)
    {
        cnt[x]++;
        x += lowbit(x);
    }
}
int query(int x)
{
    int ans = 0;
    while (x > 0)
    {
        ans += cnt[x];
        x -= lowbit(x);
    }
    return ans;
}
void dfs(int now, int deep, int fa)
{
    for (int id : wt[now])
    {
        wts[id].ans = query(n) - query(wts[id].dp - 1);
    }
    edit(deep);
    for (int nxt : to[now])
    {
        if (nxt == fa)
        {
            continue;
        }
        dfs(nxt, deep + 1, now);
    }
    for (int id : wt[now])
    {
        wts[id].ans = query(n) - query(wts[id].dp - 1) - wts[id].ans;
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        to[x].push_back(y), to[y].push_back(x);
    }
    int yellow = n + 1;
    for (int i = 1; i <= m; i++)
    {
        int op, x;
        cin >> op >> x;
        if (op == 1)
        {
            yellow = x;
        }
        else
        {
            wts[++pos] = WT{yellow, 0};
            wt[x].push_back(pos);
        }
    }
    dfs(1, 1, 0);
    for (int i = 1; i <= pos; i++)
    {
        cout << wts[i].ans << endl;
    }
    return 0;
}