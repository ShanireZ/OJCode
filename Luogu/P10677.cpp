#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct Node
{
    int x, y;
};
int n, m, ms[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
vector<Node> p[30];
string s[1005];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        string tmp;
        cin >> tmp;
        s[i] = '#' + tmp;
        for (int j = 1; j <= m; j++)
        {
            if (s[i][j] != '#')
            {
                p[s[i][j] - 'A'].push_back(Node{i, j});
            }
        }
    }
    for (int i = 25; i >= 0; i--)
    {
        if (p[i].empty())
        {
            continue;
        }
        char ans = char(0);
        for (int j = 0; j < (int)p[i].size(); j++)
        {
            int x = p[i][j].x, y = p[i][j].y;
            for (int k = 0; k < 4; k++)
            {
                int nx = x + ms[k][0], ny = y + ms[k][1];
                if (nx < 1 || nx > n || ny < 1 || ny > m || s[nx][ny] == '#')
                {
                    continue;
                }
                ans = max(ans, s[nx][ny]);
            }
        }
        if (ans == char(0))
        {
            cout << char(i + 'A') << endl;
        }
        else if (ans == char(i + 'A'))
        {
            cout << ans << endl;
        }
        else
        {
            cout << char(i + 'A') << ans << endl;
        }
        return 0;
    }
    return 0;
}