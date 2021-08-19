#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
#define maxsz 10005
long long read();
struct Edge
{
    int to, k;
    long long w;
    Edge(int TO, long long W, int K)
    {
        to = TO, w = W, k = K;
    }
    bool operator<(const Edge oth) const
    {
        return w > oth.w;
    }
};
vector<Edge> ns[maxsz];
long long dp[maxsz][25];
int n, m, k;
priority_queue<Edge> q;
long long dijk(int st)
{
    memset(dp, 0x3f, sizeof(dp));
    dp[st][0] = 0;
    for (int i = 0; i < ns[st].size(); i++)
    {
        q.push(ns[st][i]);
        q.push(Edge(ns[st][i].to, 0, 1));
    }
    while (q.size())
    {
        Edge tmp = q.top();
        q.pop();
        int now = tmp.to, times = tmp.k;
        long long w = tmp.w;
        if (dp[now][times] != 0x3f3f3f3f3f3f3f3f)
        {
            continue;
        }
        dp[now][times] = w;
        for (int i = 0; i < ns[now].size(); i++)
        {
            int to = ns[now][i].to;
            long long tw = ns[now][i].w;
            if (dp[to][times] == 0x3f3f3f3f3f3f3f3f) //不改造
            {
                q.push(Edge(to, w + tw, times));
            }
            if (dp[to][times + 1] == 0x3f3f3f3f3f3f3f3f && times < k) //改造
            {
                q.push(Edge(to, w, times + 1));
            }
        }
    }
    long long ans = 0x3f3f3f3f3f3f3f3f;
    for (int i = 0; i <= k; i++)
    {
        ans = min(ans, dp[n][i]);
    }
    return ans;
}
int main()
{
    n = read(), m = read(), k = read();
    for (int i = 1; i <= m; i++)
    {
        int u = read(), v = read();
        long long w = read();
        ns[u].push_back(Edge(v, w, 0));
        ns[v].push_back(Edge(u, w, 0));
    }
    printf("%lld\n", dijk(1));
    return 0;
}
long long read()
{
    long long ans = 0, type = 1;
    char ch = getchar();
    while (ch != '-' && (ch > '9' || ch < '0'))
    {
        ch = getchar();
    }
    if (ch == '-')
    {
        type = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        ans = ans * 10 + ch - '0';
        ch = getchar();
    }
    return ans * type;
}