#include <algorithm>
#include <iostream>
using namespace std;
int a[250][250], n, m, k, res;
int main()
{
    cin >> n >> m >> k;
    while (k--)
    {
        int sx, sy, fx, fy;
        cin >> sx >> sy >> fx >> fy;
        for (int i = sx; i <= fx; i++)
        {
            for (int j = sy; j <= fy; j++)
            {
                a[i][j] = 1;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            res += (a[i][j] != 0);
        }
    }
    cout << res << endl;
    return 0;
}