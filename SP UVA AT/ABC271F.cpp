#include <algorithm>
#include <iostream>
#include <map>
using namespace std;
struct Node
{
    int x, y, v;
    bool operator<(const Node &oth) const
    {
        if (x == oth.x)
        {
            if (y == oth.y)
            {
                return v < oth.v;
            }
            return y < oth.y;
        }
        return x < oth.x;
    }
};
int n, a[35][35];
long long ans;
map<Node, long long> mp;
void dfs1(int x, int y, int now)
{
    if (x + y == n + 1)
    {
        mp[Node{x, y, now}]++;
        return;
    }
    if (x + 1 <= n)
    {
        dfs1(x + 1, y, now ^ a[x + 1][y]);
    }
    if (y + 1 <= n)
    {
        dfs1(x, y + 1, now ^ a[x][y + 1]);
    }
}
void dfs2(int x, int y, int now)
{
    if (x + y == n + 1)
    {
        ans += mp[Node{x, y, now ^ a[x][y]}];
        return;
    }
    if (x - 1 > 0)
    {
        dfs2(x - 1, y, now ^ a[x - 1][y]);
    }
    if (y - 1 > 0)
    {
        dfs2(x, y - 1, now ^ a[x][y - 1]);
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    dfs1(1, 1, a[1][1]);
    dfs2(n, n, a[n][n]);
    cout << ans << endl;
    return 0;
}
// TAG: 双向搜索 meet in the middle