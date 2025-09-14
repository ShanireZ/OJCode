#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
struct Node
{
    int x, y;
};
queue<Node> q;
string s[100005];
int n, m, ans, sx, sy;
int ms[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
void add(char ch)
{
    if (ch == 'S')
    {
        ans += 1;
    }
    else if (ch == 'M')
    {
        ans += 5;
    }
    else if (ch == 'L')
    {
        ans += 10;
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    cin >> sx >> sy;
    q.push(Node{sx, sy}), add(s[sx][sy]), s[sx][sy] = '*';
    while (q.size())
    {
        int x = q.front().x, y = q.front().y;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int tx = x + ms[i][0], ty = y + ms[i][1];
            if (tx >= 0 && tx < n && ty >= 0 && ty < m && s[tx][ty] != '*')
            {
                q.push(Node{tx, ty}), add(s[tx][ty]), s[tx][ty] = '*';
            }
        }
    }
    cout << ans << endl;
    return 0;
}