#include <iostream>
#include <cstring>
using namespace std;
// a[i] 第i列匹配哪一行 b[j] 第j行被哪一列匹配
int mp[205][205], usd[205], a[205], b[205], n;
bool dfs(int now, int tag)
{
    if (usd[now] == tag)
    {
        return 0;
    }
    usd[now] = tag;
    for (int i = 1; i <= n; i++) //枚举每一行
    {
        if (mp[i][now] == 0)
        {
            continue;
        }
        if (b[i] == 0 || dfs(b[i], tag))
        {
            b[i] = now;
            a[now] = i;
            return 1;
        }
    }
    return 0;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        memset(usd, 0, sizeof(usd));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cin >> mp[i][j];
            }
        }
        int trig = 1;
        for (int i = 1; i <= n; i++) // 枚举每一列
        {
            if (dfs(i, i) == 0)
            {
                trig = 0;
                break;
            }
        }
        if (trig)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    return 0;
}