#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;
double item[1005][5], px, py;
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> item[i][0] >> item[i][1] >> item[i][2];
        px += item[i][0] / n, py += item[i][1] / n;
    }
    double mx = 1e5, my = 1e5, t = 5000;
    while (t >= 1e-5 && (fabs(mx) > 1e-5 || fabs(my) > 1e-5))
    {
        mx = my = 0;
        for (int i = 1; i <= n; i++)
        {
            double d = sqrt((px - item[i][0]) * (px - item[i][0]) + (py - item[i][1]) * (py - item[i][1]));
            if (d == 0)
            {
                continue;
            }
            mx += (px - item[i][0]) / d * item[i][2], my += (py - item[i][1]) / d * item[i][2];
        }
        double d = sqrt(mx * mx + my * my);
        if (d == 0)
        {
            break;
        }
        mx = mx / d * t, my = my / d * t;
        px -= mx, py -= my, t *= 0.99;
    }
    cout << fixed << setprecision(3) << px << " " << py << endl;
    return 0;
}
// TAG: 模拟退火 几何 爬山算法