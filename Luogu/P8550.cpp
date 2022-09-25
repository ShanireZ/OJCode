#include <algorithm>
#include <iostream>
using namespace std;
int a[10], ans, n, x;
void dfs(int now, int tot, int t)
{
    if (now > n)
    {
        if (t == 0)
        {
            return;
        }
        if (tot == 0 || abs(x) % abs(tot) != 0 || x / abs(x) == tot / abs(tot))
        {
            ans = 1;
        }
        return;
    }
    dfs(now + 1, tot, t);
    dfs(now + 1, tot + a[now], t + 1);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ans = 0;
        cin >> n >> x;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        sort(a + 1, a + 1 + n);
        n = unique(a + 1, a + 1 + n) - (a + 1);
        dfs(1, 0, 0);
        if (ans)
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