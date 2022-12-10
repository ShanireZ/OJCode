#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
#define MX 5005
struct Prob
{
    int id, day;
};
queue<Prob> q;
int read(), ind[MX], ans[MX], last[MX], pre[MX * MX], to[MX * MX], pos;
int main()
{
    int n = read(), k = read(), p = read();
    for (int i = 1; i <= p; i++)
    {
        q.push(Prob{read(), 0});
    }
    int r = read();
    for (int i = 1; i <= r; i++)
    {
        int v = read(), s = read();
        ind[v] += s;
        for (int j = 1; j <= s; j++)
        {
            int u = read();
            pre[++pos] = last[u];
            to[pos] = v, last[u] = pos;
        }
    }
    memset(ans, -1, sizeof(ans));
    while (q.size())
    {
        int now = q.front().id;
        ans[now] = q.front().day, q.pop();
        for (int i = last[now]; i; i = pre[i])
        {
            int nxt = to[i];
            if (--ind[nxt] == 0 && ans[nxt] == -1)
            {
                q.push(Prob{nxt, ans[now] + 1});
            }
        }
    }
    printf("%d\n", ans[k]);
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