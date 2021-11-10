#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
int read();
struct Cow
{
    int a, t, rk;
};
struct cmprk
{
    bool operator()(Cow a, Cow b)
    {
        return a.rk > b.rk;
    }
};
bool cmpa(Cow a, Cow b)
{
    return a.a < b.a;
}
Cow cow[100005];
priority_queue<Cow, vector<Cow>, cmprk> q;
int main()
{
    int n = read(), ans = 0;
    for (int i = 1; i <= n; i++)
    {
        cow[i].a = read(), cow[i].t = read();
        cow[i].rk = i;
    }
    sort(cow + 1, cow + 1 + n, cmpa);
    int p = 1, t = 0;
    while (p <= n)
    {
        if (q.size() == 0)
        {
            q.push(cow[p]);
            p++;
        }
        while (q.size())
        {
            t = max(t, q.top().a);
            ans = max(ans, t - q.top().a);
            t += q.top().t;
            q.pop();
            while (p <= n && cow[p].a <= t)
            {
                q.push(cow[p]);
                p++;
            }
        }
    }
    printf("%d\n", ans);
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