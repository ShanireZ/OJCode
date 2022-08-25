#include <cstring>
#include <iostream>
using namespace std;
int n, k, es[505][505], back[505], vis[505];
bool dfs(int now, int turn)
{
    if (vis[now] == turn)
    {
        return false;
    }
    vis[now] = turn;
    for (int i = 1; i <= n; i++)
    {
        if (es[now][i] == 0)
        {
            continue;
        }
        if (back[i] == 0 || dfs(back[i], turn))
        {
            back[i] = now;
            return true;
        }
    }
    return false;
}
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= k; i++)
    {
        int x, y;
        cin >> x >> y;
        es[x][y] = 1;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += dfs(i, i);
    }
    cout << ans << endl;
    return 0;
}