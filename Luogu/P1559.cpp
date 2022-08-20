#include <iostream>
using namespace std;
int n, pos, epos, ans, c, p[25][25], q[25][25], last[25], pre[405], to[405], d[405];
int bv[25], gv[25], visb[25], visg[25], back[25];
void addEdge(int u, int v, int w, int id)
{
    pre[id] = last[u], to[id] = v, d[id] = w;
    last[u] = id;
}
bool dfs(int now, int turn)
{
    if (visb[now] == turn)
    {
        return 0;
    }
    visb[now] = turn;
    for (int i = last[now]; i; i = pre[i])
    {
        int t = to[i], w = d[i];
        if (bv[now] + gv[t] == w)
        {
            visg[t] = turn;
            if (back[t] == 0 || dfs(back[t], turn))
            {
                back[t] = now;
                return 1;
            }
        }
        else
        {
            c = min(c, bv[now] + gv[t] - w);
        }
    }
    return 0;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> p[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> q[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            addEdge(i, j, p[i][j] * q[j][i], ++epos);
            bv[i] = max(bv[i], p[i][j] * q[j][i]);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        c = 0x3f3f3f3f;
        while (dfs(i, ++pos) == false)
        {
            for (int j = 1; j <= n; j++)
            {
                if (visb[j] == pos)
                {
                    bv[j] -= c;
                }
                if (visg[j] == pos)
                {
                    gv[j] += c;
                }
            }
            c = 0x3f3f3f3f;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        ans += bv[i] + gv[i];
    }
    cout << ans << endl;
    return 0;
}