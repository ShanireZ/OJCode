#include <iostream>
using namespace std;
int ans[305], r[305][305], n, ok;
int check(int now)
{
    int maxa = max(ans[now], ans[now - 1]), mina = min(ans[now], ans[now - 1]);
    for (int i = now - 2; i >= 1; i--)
    {
        maxa = max(maxa, ans[i]), mina = min(mina, ans[i]);
        if (maxa - mina != r[i][now])
        {
            return 0;
        }
    }
    return 1;
}
void dfs(int now)
{
    if (now > n)
    {
        ok = 1;
        for (int i = 1; i <= n; i++)
        {
            cout << ans[i] << " ";
        }
        return;
    }
    ans[now] = ans[now - 1] + r[now - 1][now];
    if (check(now) && ok == 0)
    {
        dfs(now + 1);
    }
    ans[now] = ans[now - 1] - r[now - 1][now];
    if (check(now) && ok == 0)
    {
        dfs(now + 1);
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            cin >> r[i][j];
        }
    }
    dfs(2); // 设a[1] = 0
    return 0;
}