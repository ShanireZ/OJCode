#include <algorithm>
#include <iostream>
using namespace std;
int n, m, pos, ok, nd[30], dn[30], rec[20], s[20][30];
bool check()
{
    for (int i = 1; i <= n; i++)
    {
        if (nd[i] > dn[i])
        {
            return false;
        }
    }
    return true;
}
void dfs(int now, int lmt)
{
    ok = check();
    if (now == m + 1 || ok)
    {
        return;
    }
    if (lmt > pos)
    {
        for (int i = 1; i <= n; i++)
        {
            dn[i] += s[now][i];
        }
        rec[++pos] = now;
        dfs(now + 1, lmt);
        if (ok)
        {
            return;
        }
        for (int i = 1; i <= n; i++)
        {
            dn[i] -= s[now][i];
        }
        pos--;
    }
    dfs(now + 1, lmt);
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> nd[i];
    }
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> s[i][j];
        }
    }
    for (int i = 1; i <= m && ok == 0; i++)
    {
        dfs(1, i);
    }
    cout << pos << " ";
    for (int i = 1; i <= pos; i++)
    {
        cout << rec[i] << " ";
    }
    return 0;
}
// TAG: ID 迭代加深 DFS