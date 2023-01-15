#include <iostream>
#include <queue>
using namespace std;
#define MX 500005
int last[MX], to[MX], pre[MX], ind1[MX], ind2[MX], read();
priority_queue<int, vector<int>, greater<int>> q1;
priority_queue<int> q2;
queue<int> q;
int main()
{
    int n = read(), m = read();
    for (int i = 1; i <= m; i++)
    {
        int u = read(), v = read();
        pre[i] = last[u], to[i] = v, last[u] = i, ind1[v]++, ind2[v]++;
    }
    for (int i = 1; i <= n; i++)
    {
        if (ind1[i] == 0)
        {
            q1.push(i);
        }
    }
    int maxn = 0, ans = 0;
    while (q1.size()) // 全部候选中找最小
    {
        int now = q1.top();
        q1.pop(), ans += (now > maxn), maxn = max(maxn, now);
        for (int i = last[now]; i; i = pre[i])
        {
            int nxt = to[i];
            if (--ind1[nxt] == 0)
            {
                q1.push(nxt);
            }
        }
    }
    printf("%d\n", ans);
    for (int i = 1; i <= n; i++)
    {
        if (ind2[i] == 0)
        {
            q2.push(i);
        }
    }
    maxn = 0, ans = 0;
    while (q2.size())
    {
        while (q2.size())
        {
            q.push(q2.top()), q2.pop();
        }
        while (q.size())
        {
            int now = q.front();
            q.pop(), ans += (now > maxn), maxn = max(maxn, now);
            for (int i = last[now]; i; i = pre[i])
            {
                int nxt = to[i];
                if (--ind2[nxt] == 0)
                {
                    (nxt > maxn) ? q2.push(nxt) : q.push(nxt);
                }
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