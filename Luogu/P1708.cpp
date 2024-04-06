#include <algorithm>
#include <iostream>
using namespace std;
int cnt[10][105];
void dfs(int now, int tot)
{
    for (int i = 0; i <= 9; i++)
    {
        if (now == 1 && i == 0)
        {
            continue;
        }
        for (int j = 100; tot + i <= j && j >= 1; j--)
        {
            cnt[now][j]++;
        }
        if (now < 7)
        {
            dfs(now + 1, tot + i);
        }
    }
}
int main()
{
    dfs(1, 0);
    int T, n, k;
    cin >> T;
    while (T--)
    {
        cin >> n >> k;
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            ans += cnt[i][k];
        }
        cout << ans << '\n';
    }
    return 0;
}