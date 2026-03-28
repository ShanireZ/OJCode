#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> to[105];
int n, ans, cnt, tot, vis[105];
string s[105];
bool check(int x, int y)
{
    int p1 = 0, p2 = 0, t = 0;
    for (int i = 0; i < 5000; i++)
    {
        if (s[x][i] != s[y][i])
        {
            p2 = p1, p1 = i, t++;
        }
    }
    if (t == 2 && s[x][p1] == s[y][p2] && s[x][p2] == s[y][p1])
    {
        return true;
    }
    return false;
}
void dfs(int now)
{
    vis[now] = 1, tot++;
    for (int nxt : to[now])
    {
        if (vis[nxt] == 0)
        {
            dfs(nxt);
        }
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
        s[i] = string(5000 - (int)s[i].size(), '0') + s[i];
        for (int j = 1; j < i; j++)
        {
            if (check(i, j))
            {
                to[i].push_back(j), to[j].push_back(i);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            cnt++, tot = 0;
            dfs(i);
            ans = max(ans, tot);
        }
    }
    cout << cnt << " " << ans << endl;
    return 0;
}