#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
struct Node
{
    int x, y;
};
queue<Node> q;
string s = "v<>^";
int ms[4][2] = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};
int n, m, mp[1005][1005], f[1005][1005];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            char ch;
            cin >> ch;
            if (ch == '.')
            {
                mp[i][j] = 9;
            }
            else if (ch == 'E')
            {
                mp[i][j] = 13, q.push(Node{i, j});
            }
        }
    }
    memset(f, -1, sizeof(f));
    while (q.size())
    {
        int x = q.front().x, y = q.front().y;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + ms[i][0], ny = y + ms[i][1];
            if (mp[nx][ny] != 9 || f[nx][ny] != -1)
            {
                continue;
            }
            f[nx][ny] = 3 - i, q.push(Node{nx, ny});
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (mp[i][j] == 0)
            {
                cout << "#";
            }
            else if (mp[i][j] == 13)
            {
                cout << "E";
            }
            else
            {
                cout << s[f[i][j]];
            }
        }
        cout << endl;
    }
    return 0;
}