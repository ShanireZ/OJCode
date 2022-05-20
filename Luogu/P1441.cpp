#include <cstring>
#include <iostream>
using namespace std;
int a[25], choose[25], tot[2005], ans, n, m;
void count()
{
    memset(tot, 0, sizeof(tot));
    int cnt = 0;
    tot[0] = 1;
    for (int i = 1; i <= n - m; i++)
    {
        for (int j = 2000; j >= 0; j--)
        {
            if (tot[j] == 0)
            {
                continue;
            }
            if (tot[j + choose[i]] == 0)
            {
                tot[j + choose[i]] = 1;
                cnt++;
            }
        }
    }
    ans = max(ans, cnt);
}
void dfs(int now, int pos, int del)
{
    if (del == m && now > n)
    {
        count();
        return;
    }
    if (n - now >= m - del) // 选now
    {
        choose[pos] = a[now];
        dfs(now + 1, pos + 1, del);
    }
    if (del < m) // 不选now
    {
        dfs(now + 1, pos, del + 1);
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    dfs(1, 1, 0);
    cout << ans << endl;
    return 0;
}