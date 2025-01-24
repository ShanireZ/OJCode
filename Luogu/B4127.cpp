#include <algorithm>
#include <iostream>
using namespace std;
long long cr[55][55], sum[55], v[2505];
int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> cr[i][j];
            sum[j] += cr[i][j];
        }
    }
    while (k--)
    {
        long long mx = 0, mn = 1e18, pos = 0;
        for (int i = 1; i <= m; i++)
        {
            mx = max(mx, sum[i]), mn = min(mn, sum[i]);
        }
        for (int i = 1; i <= m; i++)
        {
            if (sum[i] == mx || sum[i] == mn)
            {
                sum[i] = 0;
                for (int j = 1; j <= n; j++)
                {
                    v[++pos] = cr[j][i];
                    cr[j][i] = 0;
                }
            }
        }
        sort(v + 1, v + 1 + pos, greater<long long>());
        for (int i = 1, p = 1; i <= n; i++)
        {
            if (i % 2 == 1)
            {
                for (int j = 1; j <= m; j++)
                {
                    if (cr[i][j] == 0)
                    {
                        cr[i][j] = v[p++];
                        sum[j] += cr[i][j];
                    }
                }
            }
            else
            {
                for (int j = m; j >= 1; j--)
                {
                    if (cr[i][j] == 0)
                    {
                        cr[i][j] = v[p++];
                        sum[j] += cr[i][j];
                    }
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << cr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}