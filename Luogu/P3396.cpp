#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
int ans[400][400], a[150005];
int main()
{
    int n, m;
    cin >> n >> m;
    int sz = sqrt(n);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        for (int p = 1; p <= sz; p++)
        {
            ans[p][i % p] += a[i];
        }
    }
    for (int i = 1; i <= m; i++)
    {
        char opt;
        int x, y;
        cin >> opt >> x >> y;
        if (opt == 'C')
        {
            for (int p = 1; p <= sz; p++)
            {
                ans[p][x % p] += y - a[x];
            }
            a[x] = y;
        }
        else
        {
            if (x <= sz)
            {
                cout << ans[x][y] << '\n';
            }
            else // 妙啊妙啊
            {
                int res = 0;
                for (int j = y; j <= n; j += x)
                {
                    res += a[j];
                }
                cout << res << '\n';
            }
        }
    }
    return 0;
}
// TAG: 分块 数学 贪心 根号分治