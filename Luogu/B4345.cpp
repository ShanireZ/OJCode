#include <algorithm>
#include <iostream>
using namespace std;
long long n, m, k, a[105][105], b[105][105];
int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            cin >> b[i][j];
        }
    }
    for (int i = 1; i + k - 1 <= n; i++)
    {
        for (int j = 1; j + k - 1 <= m; j++)
        {
            long long tot = 0;
            for (int x = 1; x <= k; x++)
            {
                for (int y = 1; y <= k; y++)
                {
                    tot += b[x][y] * a[i + x - 1][j + y - 1];
                }
            }
            cout << tot << " ";
        }
        cout << endl;
    }
    return 0;
}