#include <algorithm>
#include <iostream>
using namespace std;
#define MX 10000005
int lc[MX], rc[MX], fa[MX], p[MX], n;
int main()
{
    cin.tie(0)->ios::sync_with_stdio(false);
    cin >> n >> p[1];
    int last = 1;
    for (int i = 2; i <= n; i++)
    {
        cin >> p[i];
        int ok = 1;
        while (p[last] > p[i])
        {
            if (fa[last] == 0)
            {
                fa[last] = i, lc[i] = last;
                ok = 0;
                break;
            }
            last = fa[last];
        }
        if (ok)
        {
            fa[i] = last, lc[i] = rc[last];
            rc[last] = i, fa[lc[last]] = i;
        }
        last = i;
    }
    long long ansl = 0, ansr = 0;
    for (int i = 1; i <= n; i++)
    {
        ansl ^= i * (lc[i] + 1ll);
        ansr ^= i * (rc[i] + 1ll);
    }
    cout << ansl << " " << ansr << endl;
    return 0;
}