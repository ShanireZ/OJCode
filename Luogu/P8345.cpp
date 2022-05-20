#include <algorithm>
#include <iostream>
using namespace std;
long long a[1000005], now[1000005];
int main()
{
    int n, c, q;
    cin >> n >> c >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= q; i++)
    {
        long long m;
        cin >> m;
        long long ans = (m - 1) * c, tot = 0;
        for (int j = 1; j <= m; j++)
        {
            int x;
            cin >> x;
            now[j] = a[x];
            tot += a[x];
        }
        sort(now + 1, now + 1 + m);
        ans += (now[1] - now[m]) - (tot - now[1]);
        cout << ans << endl;
    }
    return 0;
}