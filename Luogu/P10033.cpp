#include <algorithm>
#include <iostream>
using namespace std;
long long a[1000005], b[1000005], vis[1000005];
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, x, pn = 0, p1 = 0;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> x;
            a[i] = n - x, b[i] = x - 1;
            pn = (x == n ? i : pn), p1 = (x == 1 ? i : p1);
        }
        if (n == 2)
        {
            cout << -1 << endl;
            continue;
        }
        for (int i = 1; i < n; i++)
        {
            vis[i] = 0;
        }
        long long pre = 0, suf = 0;
        for (int i = pn; i <= n; i++)
        {
            suf += a[i], pre = 0;
            for (int j = pn; j >= 1 && suf + pre + a[j] < n; j--)
            {
                pre += a[j];
                vis[pre + suf] = 1;
            }
        }
        int ok = 0;
        for (int i = 1; i < n; i++)
        {
            if (vis[i] == 0)
            {
                for (int j = 1; j <= n; j++)
                {
                    cout << (j == pn ? n - i : n) << " ";
                }
                cout << endl;
                ok = 1;
                break;
            }
        }
        if (ok)
        {
            continue;
        }
        for (int i = 1; i < n; i++)
        {
            vis[i] = 0;
        }
        pre = 0, suf = 0;
        for (int i = p1; i <= n; i++)
        {
            suf += b[i], pre = 0;
            for (int j = p1; j >= 1 && suf + pre + b[j] < n; j--)
            {
                pre += b[j];
                vis[pre + suf] = 1;
            }
        }
        for (int i = 1; i < n; i++)
        {
            if (vis[i] == 0)
            {
                for (int j = 1; j <= n; j++)
                {
                    cout << (j == p1 ? i + 1 : 1) << " ";
                }
                cout << endl;
                break;
            }
        }
    }
    return 0;
}
// TAG: 构造 贪心
// 特殊样例: 3 4 2 1