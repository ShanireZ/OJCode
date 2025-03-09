#include <algorithm>
#include <iostream>
using namespace std;
int prim[205], vis[205], n, pos, ans;
void f(int now, int sum, int cnt)
{
    if (sum == n)
    {
        ans = max(ans, cnt);
    }
    if (now > pos)
    {
        return;
    }
    if (sum + prim[now] <= n)
    {
        vis[now] = 1;
        f(now + 1, sum + prim[now], cnt + 1);
        vis[now] = 0;
    }
    f(now + 1, sum, cnt);
}
int main()
{
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            prim[++pos] = i;
        }
        for (int j = 1; j <= pos && prim[j] * i <= n; j++)
        {
            vis[prim[j] * i] = 1;
            if (i % prim[j] == 0)
            {
                break;
            }
        }
    }
    f(1, 0, 0);
    cout << ans << endl;
    return 0;
}