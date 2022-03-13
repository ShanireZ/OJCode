#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;
int main()
{
    double st, eachm;
    int m;
    cin >> st >> eachm >> m;
    double l = 0, r = 5;
    while (l <= r)
    {
        double mid = (l + r) / 2;
        double now = st;
        for (int i = 1; i <= m; i++)
        {
            now *= 1 + mid;
            now -= eachm;
        }
        if (now >= 0)
        {
            r = mid - 0.0001;
        }
        else
        {
            l = mid + 0.0001;
        }
    }
    cout << fixed << setprecision(1) << l * 100 << endl;
    return 0;
}