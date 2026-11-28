#include <algorithm>
#include <iostream>
using namespace std;
int n, m, a[305], b[305], res[305];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> b[i];
    }
    int ok = 1;
    while (ok)
    {
        ok = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (a[i] >= b[j])
                {
                    res[i] += b[j];
                    ok = 1, b[j] = 1e9;
                    break;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << res[i] << " ";
    }
    return 0;
}