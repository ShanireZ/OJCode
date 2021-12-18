#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int mp[55][55];
int n, turn, cnt;
void dfs(int x, int y, int f, int t) // f方向1右2下
{
    if (t > turn || x > n || y > n || mp[x][y] == 1)
    {
        return;
    }
    if (x == n && y == n)
    {
        cnt++;
        return;
    }
    if (f == 1)
    {
        dfs(x, y + 1, 1, t);
        dfs(x + 1, y, 2, t + 1);
    }
    else
    {
        dfs(x + 1, y, 2, t);
        dfs(x, y + 1, 1, t + 1);
    }
}
int main()
{
    int t;
    cin >> t;
    for (int times = 1; times <= t; times++)
    {
        memset(mp, 0, sizeof(mp));
        cnt = 0;
        cin >> n >> turn;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                char ch;
                cin >> ch;
                if (ch == 'H')
                {
                    mp[i][j] = 1;
                }
            }
        }
        dfs(1, 2, 1, 0);
        dfs(2, 1, 2, 0);
        cout << cnt << endl;
    }
    return 0;
}