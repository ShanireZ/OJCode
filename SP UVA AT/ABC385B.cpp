#include <algorithm>
#include <iostream>
using namespace std;
int mp[105][105], ms[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
char fw[4] = {'U', 'D', 'L', 'R'};
int main()
{
    int n, m, x, y, cnt = 0;
    cin >> n >> m >> x >> y;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            char ch;
            cin >> ch;
            mp[i][j] = (ch == '.' ? 0 : (ch == '@' ? 1 : -1));
        }
    }
    char t;
    while (cin >> t)
    {
        for (int i = 0; i < 4; i++)
        {
            if (t == fw[i])
            {
                t = i;
            }
        }
        int nx = x + ms[t][0], ny = y + ms[t][1];
        if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && mp[nx][ny] >= 0)
        {
            x = nx, y = ny;
            cnt += mp[x][y];
            mp[x][y] = 0;
        }
    }
    cout << x << " " << y << " " << cnt << endl;
    return 0;
}