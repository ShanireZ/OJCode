#include <algorithm>
#include <iostream>
using namespace std;
int a[105][105], n, m, r, res;
int main()
{
    cin >> n >> m >> r;
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if ((i - x) * (i - x) + (j - y) * (j - y) <= r * r)
                {
                    a[i][j] = 1;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            res += a[i][j];
        }
    }
    cout << res << endl;
    return 0;
}