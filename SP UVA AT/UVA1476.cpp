#include <iomanip>
#include <iostream>
using namespace std;
double xs[10005][5];
int n, t;
double makeans(double pos)
{
    double ans = xs[1][2] * pos * pos + xs[1][1] * pos + xs[1][0];
    for (int i = 2; i <= n; i++)
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
            double m = (r - l) / 3;
            if (makeans(l + m) > makeans(r - m))
            {
                l = l + m;
            }
            else
            {
                r = r - m;
            }
        }
        printf("%.4lf\n", makeans(l));
    }
    return 0;
}