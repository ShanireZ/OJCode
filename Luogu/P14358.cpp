#include <algorithm>
#include <iostream>
using namespace std;
int a[105], z[15][15], n, m, r;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n * m; i++)
    {
        cin >> a[i];
    }
    r = a[1];
    sort(a + 1, a + n * m + 1);
    for (int j = 1, pos = n * m; j <= m; j++)
    {
        if (j % 2 == 1)
        {
            for (int i = 1; i <= n; i++)
            {
                z[i][j] = a[pos--];
                if (z[i][j] == r)
                {
                    cout << j << " " << i << endl;
                    return 0;
                }
            }
        }
        else
        {
            for (int i = n; i >= 1; i--)
            {
                z[i][j] = a[pos--];
                if (z[i][j] == r)
                {
                    cout << j << " " << i << endl;
                    return 0;
                }
            }
        }
    }
    return 0;
}