#include <cstring>
#include <iostream>
using namespace std;
int a[25], choose[25], tot[2005], ans, n, m, pos;
void count()
{
    memset(tot, 0, sizeof(tot)), tot[0] = 1;
    int cnt = 0;
    for (int i = 1; i <= n - m; i++)
    {
        for (int j = 2000; j >= 0; j--)
        {
            if (tot[j] != 0 && tot[j + choose[i]] == 0)
            {
                tot[j + choose[i]] = 1, cnt++;
            }
        }
    }
    ans = max(ans, cnt);
}
void dfs(int now, int del)
{
    if (now > n)
    {
        if (del == m)
        {
            count();
        }
        return;
    }
    if (n - now >= m - del) // 选now
    {
        choose[++pos] = a[now];
        dfs(now + 1, del);
        pos--;
    }
    if (del < m) // 不选now
    {
        dfs(now + 1, del + 1);
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    dfs(1, 0);
    cout << ans << endl;
    return 0;
}