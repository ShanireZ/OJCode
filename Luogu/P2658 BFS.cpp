#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
struct Node
{
    int x, y;
};
Node st;
int m, n, tot, h[505][505], sig[505][505], vis[505][505];
int ms[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
bool check(int lim)
{
    memset(vis, 0, sizeof(vis));
    queue<Node> q;
    q.push(st), vis[st.x][st.y] = 1;
    int cnt = 1;
    while (q.size())
    {
        Node now = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int x = now.x + ms[i][0], y = now.y + ms[i][1];
            if (x < 1 || y < 1 || x > m || y > n || vis[x][y] || abs(h[x][y] - h[now.x][now.y]) > lim)
            {
                continue;
            }
            q.push(Node{x, y}), vis[x][y] = 1;
            cnt += sig[x][y];
        }
        if (cnt == tot)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> h[i][j];
        }
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> sig[i][j];
            if (sig[i][j])
            {
                st.x = i, st.y = j, tot++;
            }
        }
    }
    int l = 0, r = 1e9;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        (check(mid)) ? r = mid - 1 : l = mid + 1;
    }
    cout << l << endl;
    return 0;
}