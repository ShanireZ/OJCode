#include <cmath>
#include <iostream>
using namespace std;
int n;
double xs[20], l, r;
double makeans(double pos)
{
    double ans = 0;
    for (int i = n; i >= 0; i--)
    {
        ans += xs[i] * pow(pos, i);
    }
    return ans;
}
int main()
{
    cin >> n >> l >> r;
    for (int i = n; i >= 0; i--)
    {
        cin >> xs[i];
    }
    double ex = 1e-6;
    while (r - l >= ex)
    {
        double mid = (l + r) / 2;
        if (makeans(mid - ex) < makeans(mid + ex))
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
    }
    printf("%.5lf", l);
    return 0;
}
// TAG: 三分 精度