#include <algorithm>
#include <iostream>
using namespace std;
#define MX 500005
long long a[MX], b[MX], c[MX], p[MX], qzb[MX], cl[MX];
int main()
{
    int n, q;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
        qzb[i] = qzb[i - 1] + b[i];          // 将1~i全部用b操作变为0需要的代价
        cl[i] = min(cl[i - 1] + b[i], a[i]); // 将1~i全部变为0需要的最小代价
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
    }
    cin >> q;
    while (q--)
    {
        int m;
        cin >> m;
        long long nb = 0, nc = 0, ans = 1e18;
        for (int i = 1; i <= m; i++)
        {
            cin >> p[i];
            nb += b[p[i]];
        }
        // 将p[i]前方用a操作全部变为0，然后再用c操作将p[1]~p[i-1]变为1
        // 再用b操作将p[i]后方非P中的位置全变为0
        for (int i = 1; i <= m; i++)
        {
            int pos = p[i] - 1;
            ans = min(ans, cl[pos] + nc + (qzb[n] - qzb[pos] - nb));
            nb -= b[p[i]], nc += c[p[i]];
        }
        ans = min(ans, cl[n] + nc); // 全部用a操作变为0，再用c操作将P中的位置变为1
        cout << ans << "\n";
    }
    return 0;
}