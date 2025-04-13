#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
struct Node
{
    int x, y;
};
int n, m, res, a[505][505], ms[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
queue<Node> q;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            char ch;
            cin >> ch;
            a[i][j] = (ch == 'R');
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i][j])
            {
                q.emplace(Node{i, j}), a[i][j] = 0, res++;
                while (q.size())
                {
                    int x = q.front().x, y = q.front().y;
                    q.pop();
                    for (int k = 0; k < 4; k++)
                    {
                        int nx = x + ms[k][0], ny = y + ms[k][1];
                        if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && a[nx][ny])
                        {
                            q.emplace(Node{nx, ny}), a[nx][ny] = 0;
                        }
                    }
                }
            }
        }
    }
    cout << res << endl;
    return 0;
}