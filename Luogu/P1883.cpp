#include <iomanip>
#include <iostream>
using namespace std;
int xs[10005][5], n, t;
double makeans(double pos)
{
    double ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, xs[i][2] * pos * pos + xs[i][1] * pos + xs[i][0]);
    }
    return ans;
}
int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> xs[i][2] >> xs[i][1] >> xs[i][0];
        }
        double l = 0, r = 1000, ex = 1e-10;
        while (r - l >= ex)
        {
            double mid = (l + r) / 2;
            if (makeans(mid - ex) > makeans(mid + ex))
            {
                l = mid;
            }
            else
            {
                r = mid;
            }
        }
        cout << fixed << setprecision(4) << makeans(l) << endl;
    }
    return 0;
}
// TAG: 三分 精度