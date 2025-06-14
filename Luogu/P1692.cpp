#include <algorithm>
#include <iostream>
using namespace std;
int n, m, len, em[105][105], zt[105], ans[105];
void dfs(int now, int c)
{
    if (now > n)
    {
        if (c > len)
        {
            len = c;
            for (int i = 1; i <= n; i++)
            {
                ans[i] = zt[i];
            }
        }
        return;
    }
    int ok = 1;
    for (int i = 1; i <= n; i++)
    {
        if (zt[i] == 1 && em[now][i] == 1)
        {
            ok = 0;
            break;
        }
    }
    if (ok)
    {
        zt[now] = 1, dfs(now + 1, c + 1);
    }
    zt[now] = 0, dfs(now + 1, c);
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        em[a][b] = em[b][a] = 1;
    }
    dfs(1, 0);
    cout << len << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}