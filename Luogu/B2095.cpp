#include <algorithm>
#include <iomanip>
#include <iostream>
using namespace std;
double a[305];
int main()
{
    int n, zd = 1, zx = 1;
    cin >> n;
    double tot = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        tot = tot + a[i];
        if (a[i] > a[zd])
        {
            zd = i;
        }
        if (a[i] < a[zx])
        {
            zx = i;
        }
    }
    double pj = (tot - a[zd] - a[zx]) / (n - 2), czd = -1;
    cout << fixed << setprecision(2) << pj << " ";
    for (int i = 1; i <= n; i++)
    {
        if (i != zd && i != zx)
        {
            if (abs(a[i] - pj) > czd)
            {
                czd = abs(a[i] - pj);
            }
        }
    }
    cout << fixed << setprecision(2) << czd;
    return 0;
}