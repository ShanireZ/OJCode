#include <iostream>
using namespace std;
struct Area
{
    int l, r, t, p;
};
Area as[15], cs[25];
int n, m, ans, lan[105];
void dfs(int now, int cost)
{
    if (now > m)
    {
        for (int i = 1; i <= n; i++) // 如果满足所有牛的降温要求
        {
            for (int j = cs[i].l; j <= cs[i].r; j++)
            {
                if (cs[i].t > lan[j])
                {
                    return;
                }
            }
        }
        ans = min(ans, cost);
        return;
    }
    for (int i = as[now].l; i <= as[now].r; i++)
    {
        lan[i] += as[now].t;
    }
    dfs(now + 1, cost + as[now].p);
    for (int i = as[now].l; i <= as[now].r; i++)
    {
        lan[i] -= as[now].t;
    }
    dfs(now + 1, cost);
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> cs[i].l >> cs[i].r >> cs[i].t;
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> as[i].l >> as[i].r >> as[i].t >> as[i].p;
        ans += as[i].p;
    }
    dfs(1, 0);
    cout << ans << "\n";
    return 0;
}