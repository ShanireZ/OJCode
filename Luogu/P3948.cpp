#include <algorithm>
#include <iostream>
using namespace std;
long long n, m, mod, l, r;
long long cf[80005], a[80005];
int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m >> mod >> l >> r;
    for (int i = 1; i <= m; i++)
    {
        char op;
        long long x, y, k;
        cin >> op >> x >> y;
        if (op == 'A')
        {
            cin >> k;
            cf[x] += k, cf[y + 1] -= k;
        }
        else
        {
            long long res = 0;
            for (int j = 1; j <= n; j++)
            {
                a[j] = a[j - 1] + cf[j];
                long long now = a[j] * j % mod;
                res += (j <= y && j >= x && now <= r && now >= l);
            }
            cout << res << "\n";
        }
    }
    for (int i = 1; i <= n; i++)
    {
        a[i] = a[i - 1] + cf[i];
        long long now = a[i] * i % mod;
        cf[i] = cf[i - 1] + (now <= r && now >= l);
    }
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        long long x, y;
        cin >> x >> y;
        cout << cf[y] - cf[x - 1] << "\n";
    }
    return 0;
}
// TAG: 前缀和 差分 线段树 模拟