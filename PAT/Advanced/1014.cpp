#include <iostream>
#include <queue>
using namespace std;
struct Pt
{
    int t, id;
    bool operator<(const Pt oth) const
    {
        if (t == oth.t)
        {
            return id > oth.id;
        }
        return t > oth.t;
    }
};
priority_queue<Pt> sim;
queue<int> dl[30];
int cost[1005], ans[1005], t1[30], tm[30];
int main() // 模拟排队+贪心选队
{
    int n, m, k, q;
    scanf("%d %d %d %d", &n, &m, &k, &q);
    for (int i = 1; i <= k; i++)
    {
        scanf("%d", &cost[i]);
    }
    for (int i = 1; i <= min(k, n * m); i++)
    {
        int now = (i % n == 0) ? n : i % n;
        dl[now].push(i);
        if (i <= n)
        {
            t1[now] = cost[i];
        }
        ans[i] = tm[now] = tm[now] + cost[i];
    }
    for (int i = 1; i <= n; i++)
    {
        sim.push(Pt{t1[i], i});
    }
    for (int i = n * m + 1; i <= k; i++)
    {
        int now = sim.top().id;
        sim.pop(), dl[now].pop(), dl[now].push(i);
        t1[now] += cost[dl[now].front()];
        ans[i] = tm[now] = tm[now] + cost[i];
        sim.push(Pt{t1[now], now});
    }
    for (int i = 1; i <= q; i++)
    {
        int x;
        scanf("%d", &x);
        if (ans[x] - cost[x] >= 540) // 按开始时间判定
        {
            printf("Sorry\n");
        }
        else
        {
            printf("%02d:%02d\n", ans[x] / 60 + 8, ans[x] % 60);
        }
    }
    return 0;
}