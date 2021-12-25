#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
long long read();
long long n, m;
struct BS
{
    long long x, t;
};
BS bs[100005];
bool cmpx(BS a, BS b)
{
    return a.x < b.x;
}
struct cmpt
{
    bool operator()(BS a, BS b)
    {
        return a.t < b.t;
    }
};
priority_queue<BS, vector<BS>, cmpt> q;
int main()
{
    n = read(), m = read();
    for (int i = 1; i <= n; i++)
    {
        bs[i].x = read(), bs[i].t = read();
    }
    sort(bs + 1, bs + 1 + n, cmpx);
    long long ans = 0, usd = 0, passed = 0;
    for (int i = 1; i <= n; i++)
    {
        usd += bs[i].x - bs[i - 1].x;
        usd += bs[i].t;
        passed++;
        q.push(bs[i]);
        while (usd > m && q.size())
        {
            usd -= q.top().t;
            q.pop();
            passed--;
        }
        ans = max(ans, passed);
    }
    printf("%lld\n", ans);
    return 0;
}
long long read()
{
    long long ans = 0;
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