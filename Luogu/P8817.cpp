#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
struct Edge
{
    int p[5];
    long long m[5];
};
Edge es[2505];
int n, m, k, cnt, pre[20005], to[20005], last[2505], vis[2505], dis[2505][2505];
long long ans, score[2505];
queue<int> q;
void addEdge(int u, int v, int id)
{
    pre[id] = last[u], to[id] = v;
    last[u] = id;
}
int main()
{
    ios::sync_with_stdio(false);
    memset(dis, 0x3f, sizeof(dis));
    cin >> n >> m >> k;
    k++;
    for (int i = 2; i <= n; i++)
    {
        cin >> score[i];
    }
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        addEdge(a, b, ++cnt), addEdge(b, a, ++cnt);
    }
    for (int st = 1; st <= n; st++)
    {
        memset(vis, 0, sizeof(vis));
        dis[st][st] = 0, q.push(st), vis[st] = 1;
        while (q.size())
        {
            int now = q.front();
            q.pop();
            for (int i = last[now]; i; i = pre[i])
            {
                int nxt = to[i];
                if (vis[nxt] == 0)
                {
                    dis[st][nxt] = dis[st][now] + 1, vis[nxt] = 1;
                    if (dis[st][nxt] < k)
                    {
                        q.push(nxt);
                    }
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) // 1-?-i 最大/次大/第三大 ?分数
    {
        for (int j = 1; j <= n; j++)
        {
            if (i != j && dis[i][j] != 0x3f3f3f3f && dis[1][j] != 0x3f3f3f3f)
            {
                for (int k = 1; k <= 3; k++)
                {
                    if (score[j] > es[i].m[k])
                    {
                        for (int x = 3; x > k; x--)
                        {
                            es[i].m[x] = es[i].m[x - 1], es[i].p[x] = es[i].p[x - 1];
                        }
                        es[i].m[k] = score[j], es[i].p[k] = j;
                        break;
                    }
                }
            }
        }
    }
    for (int i = 2; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (dis[i][j] != 0x3f3f3f3f)
            {
                for (int a = 1; a <= 3; a++)
                {
                    if (es[i].m[a] == 0)
                    {
                        break;
                    }
                    for (int b = 1; b <= 3; b++)
                    {
                        if (es[j].m[b] == 0)
                        {
                            break;
                        }
                        if (es[i].p[a] == j || es[j].p[b] == i || es[i].p[a] == es[j].p[b])
                        {
                            continue;
                        }
                        ans = max(ans, score[i] + score[j] + es[i].m[a] + es[j].m[b]);
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}