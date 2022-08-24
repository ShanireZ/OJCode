#include <cstring>
#include <iostream>
using namespace std;
int n, m, epos, last[1005], pre[4005], to[4005], color[1005], vis[1005], back[1005];
void addEdge(int u, int v, int id)
{
    pre[id] = last[u], to[id] = v;
    last[u] = id;
}
void makec(int now, int c)
{
    color[now] = c;
    for (int i = last[now]; i; i = pre[i])
    {
        int t = to[i];
        if (color[t] != -1)
        {
            continue;
        }
        makec(t, !c);
    }
}
bool dfs(int now, int turn)
{
    if (vis[now] == turn)
    {
        return false;
    }
    vis[now] = turn;
    for (int i = last[now]; i; i = pre[i])
    {
        int t = to[i];
        if (back[t] == 0 || dfs(back[t], turn))
        {
            back[t] = now;
            return true;
        }
    }
    return false;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        a++, b++;
        addEdge(a, b, ++epos);
        addEdge(b, a, ++epos);
    }
    memset(color, -1, sizeof(color));
    for (int i = 1; i <= n; i++)
    {
        if (color[i] == -1)
        {
            makec(i, 1);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (color[i] == 1)
        {
            ans += dfs(i, i);
        }
    }
    cout << n - ans << endl;
    return 0;
}