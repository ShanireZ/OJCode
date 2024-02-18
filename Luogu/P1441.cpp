#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
int a[25], choose[25], dp[2005], n, m, ans;
void dfs(int now, int cnt)
{
    if (now > n)
    {
        if (cnt == n - m) // todo 统计一下能组合出多少个不同的重量
        {
            memset(dp, 0, sizeof(dp));
            int res = 0;
            dp[0] = 1;
            for (int i = 1; i <= n - m; i++)
            {
                for (int j = 2000; j >= 0; j--)
                {
                    if (dp[j] == 1 && dp[j + choose[i]] == 0)
                    {
                        dp[j + choose[i]] = 1, res++;
                    }
                }
            }
            ans = max(ans, res);
        }
        return;
    }
    choose[cnt + 1] = a[now];
    dfs(now + 1, cnt + 1);
    dfs(now + 1, cnt);
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    dfs(1, 0); // todo 搜索枚举所有组合
    cout << ans << endl;
    return 0;
}