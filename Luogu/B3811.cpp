#include <algorithm>
#include <iostream>
using namespace std;
long long mp[105][105], h[105], l[105];
int main()
{
    int n, m, k, t = 0, cnt = 0;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> mp[i][j];
            h[i] += mp[i][j], l[j] += mp[i][j];
        }
    }
    while (cnt < k)
    {
        t++, cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                mp[i][j]--, h[i]--, l[j]--;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (mp[i][j] >= h[i] + l[j])
                {
                    cnt++;
                }
            }
        }
    }
    cout << t << endl;
    return 0;
}