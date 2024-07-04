#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;
int a[1005], n;
int main()
{
    cin >> n;
    double mx = 1e9;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i]++;
    }
    sort(a + 1, a + 1 + n);
    n = unique(a + 1, a + 1 + n) - a - 1;
    for (int i = 1; i <= n; i++)
    {
        mx = min(mx, 1.0 * a[i] / i);
    }
    for (double x = mx; x >= 1.0; x -= 1e-6)
    {
        int ok = 1;
        for (int j = 1; j <= n; j++)
        {
            int t = a[j] / x;
            if (abs(ceil(t * x) - a[j]) > 1e-6)
            {
                ok = 0;
                break;
            }
        }
        if (ok)
        {
            cout << fixed << setprecision(6) << x << endl;
            return 0;
        }
    }
    return 0;
}