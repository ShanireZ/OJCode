#include <algorithm>
#include <iostream>
using namespace std;
int read()
{
    int ans = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        ans = ans * 10 + ch - '0';
        ch = getchar();
    }
    return ans;
}
int mp[2005][2005], cnt[15], ms[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
long long ans = 0;
int main()
{
    int n = read(), m = read();
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> mp[i][j];
            cnt[mp[i][j]]++;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            ans += cnt[mp[i][j]] - 1;
            for (int k = 0; k < 4; k++)
            {
                int x = i + ms[k][0], y = j + ms[k][1];
                if (x >= 1 && x <= n && y >= 1 && y <= m && mp[i][j] == mp[x][y])
                {
                    ans--;
                }
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}
// TAG: 枚举 模拟 贪心