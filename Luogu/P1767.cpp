#include <iostream>
#include <queue>
#include <string>
using namespace std;
struct Node
{
    int x, y;
};
string s;
int ms[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}, mp[105][205], n, m, cnt;
queue<Node> q;
void bfs(int a, int b)
{
    q.push(Node{a, b}), mp[a][b] = ++cnt;
    while (q.size())
    {
        int x = q.front().x, y = q.front().y;
        q.pop();
        for (int k = 0; k < 4; k++)
        {
            int nx = x + ms[k][0], ny = y + ms[k][1];
            if (nx < 1 || ny < 1 || nx > n || ny > m || mp[nx][ny] != -1)
            {
                continue;
            }
            q.push(Node{nx, ny}), mp[nx][ny] = cnt;
        }
    }
}
int main()
{
    cin >> n;
    getline(cin, s);
    for (int i = 1; i <= n; i++)
    {
        getline(cin, s);
        int p = 0;
        while (s[p] == ' ' || s[p] == '*' || (s[p] >= 'a' && s[p] <= 'z'))
        {
            if (s[p] >= 'a' && s[p] <= 'z')
            {
                mp[i][p + 1] = -1;
            }
            p++;
        }
        m = max(m, p);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (mp[i][j] == -1)
            {
                bfs(i, j);
            }
        }
    }
    cout << cnt << endl;
    return 0;
}