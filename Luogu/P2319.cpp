#include <cstring>
#include <iostream>
using namespace std;
int n, m, p, es[1005][1005], vis[1005], back[1005], forw[1005];
bool dfs(int now, int turn)
{
    if (vis[now] == turn)
    {
        return false;
    }
    vis[now] = turn;
    for (int i = 0; i < n; i++)
    {
        if (es[now][i] == 0)
        {
            continue;
        }
        if (back[i] == -1 || dfs(back[i], turn))
        {
            back[i] = now, forw[now] = i;
            return true;
        }
    }
    return false;
}
int main()
{
    memset(back, -1, sizeof(back));
    memset(forw, -1, sizeof(forw));
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        es[i][a] = es[i][b] = 1;
    }
    for (int i = 1; i <= m; i++)
    {
        p++;
        if (dfs(i, i) == false)
        {
            p--;
            break;
        }
    }
    cout << p << endl;
    for (int i = 1; i <= p; i++)
    {
        cout << forw[i] << endl;
    }
    return 0;
}