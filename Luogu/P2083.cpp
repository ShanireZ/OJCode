#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct Room
{
    int x, y;
};
vector<Room> rs[1005][105];
int ans = 0x3f3f3f3f, n, m, v, fx, fy, vis[1005][105];
void dfs(int x, int y, int t)
{
    if (x == 1)
    {
        ans = min(ans, t);
        return;
    }
    for (Room nxt : rs[x][y])
    {
        if (vis[nxt.x][nxt.y])
        {
            continue;
        }
        vis[x][y] = 1;
        dfs(nxt.x, nxt.y, t + abs(x - nxt.x));
        vis[x][y] = 0;
    }
}
int main()
{
    cin >> n >> m >> v >> fx >> fy;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int a, b;
            cin >> a >> b;
            if (a == i && b == j)
            {
                continue;
            }
            rs[a][b].push_back(Room{i, j});
        }
    }
    vis[fx][fy] = 1, dfs(fx, fy, 0);
    if (ans == 0x3f3f3f3f)
    {
        cout << "impossible" << endl;
    }
    else
    {
        cout << ans * v << endl;
    }
    return 0;
}