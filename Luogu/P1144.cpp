#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
#define MX 1000005
#define MOD 100003
int read(), cnt[MX], dis[MX], last[MX], pre[MX * 4], to[MX * 4], epos;
queue<int> q;
void addEdge(int u, int v, int id)
{
    pre[id] = last[u], to[id] = v, last[u] = id;
}
int main()
{
    int n = read(), m = read();
    for (int i = 1; i <= m; i++)
    {
        int a = read(), b = read();
        addEdge(a, b, ++epos), addEdge(b, a, ++epos);
    }
    memset(dis, 0x3f, sizeof(dis));
    dis[1] = 0, cnt[1] = 1, q.push(1);
    while (q.size())
    {
        int now = q.front();
        q.pop();
        for (int i = last[now]; i; i = pre[i])
        {
            int nxt = to[i];
            if (dis[now] + 1 == dis[nxt])
            {
                cnt[nxt] = (cnt[nxt] + cnt[now]) % MOD;
            }
            else if (dis[now] + 1 < dis[nxt])
            {
                dis[nxt] = dis[now] + 1;
                q.push(nxt), cnt[nxt] = cnt[now];
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        printf("%d\n", cnt[i]);
    }
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