#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
struct Node
{
    int x, y;
};
queue<Node> q;
Node ns[2005];
int t[1005][1005], vis[1005][1005], ms[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        memset(t, 0x3f, sizeof(t));
        memset(vis, 0, sizeof(vis));
        int n, now = 1;
        cin >> n;
        for (int i = 1; i <= n * 2 - 2; i++)
        {
            cin >> ns[i].x >> ns[i].y;
        }
        q.push(Node{1, 1}), t[1][1] = 0;
        while (q.size())
        {
            int x = q.front().x, y = q.front().y;
            q.pop();
            if (t[x][y] == now) // 说明已经遍历完当前障碍落下之前的所有情况
            {
                int a = ns[now].x, b = ns[now].y;
                vis[a][b] = 1, now++;
            }
            for (int i = 0; i < 4; i++)
            {
                int nx = x + ms[i][0], ny = y + ms[i][1];
                if (nx > n || nx < 1 || ny > n || ny < 1 || vis[nx][ny])
                {
                    continue;
                }
                if (t[nx][ny] > t[x][y] + 1)
                {
                    q.push(Node{nx, ny}), t[nx][ny] = t[x][y] + 1;
                }
            }
        }
        cout << (t[n][n] == 0x3f3f3f3f ? "No" : "Yes") << endl;
    }
}