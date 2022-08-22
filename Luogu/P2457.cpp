#include <cstring>
#include <iostream>
using namespace std;
int n, pos, ans, mins, w[155][155], va[155], vb[155], visa[155], visb[155], back[155];
bool dfs(int now, int turn)
{
    if (visa[now] == turn)
    {
        return false;
    }
    visa[now] = turn;
    for (int i = 1; i <= n; i++)
    {
        if (va[now] + vb[i] == w[now][i])
        {
            visb[i] = turn;
            if (back[i] == 0 || dfs(back[i], turn))
            {
                back[i] = now;
                return true;
            }
        }
        else
        {
            mins = min(mins, va[now] + vb[i] - w[now][i]);
        }
    }
    return false;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) // 现在所在仓库
    {
        for (int j = 1; j <= n; j++) // 货号
        {
            int x;
            cin >> x;
            for (int k = 1; k <= n; k++) // 转运后仓库
            {
                if (i == k)
                {
                    continue;
                }
                w[j][k] -= x;
            }
        }
    }
    memset(va, -0x3f, sizeof(va));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            va[i] = max(va[i], w[i][j]);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        mins = 0x3f3f3f3f;
        while (dfs(i, ++pos) == false)
        {
            for (int i = 1; i <= n; i++)
            {
                if (visa[i] == pos)
                {
                    va[i] -= mins;
                }
                if (visb[i] == pos)
                {
                    vb[i] += mins;
                }
            }
            mins = 0x3f3f3f3f;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        ans -= va[i] + vb[i];
    }
    cout << ans << endl;
    return 0;
}