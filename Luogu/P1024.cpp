#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int num[5], pos;
int main()
{
    double a, b, c, d;
    cin >> a >> b >> c >> d;
    for (int i = -10000; i <= 10000; i++)
    {
        double ans = a * pow(i, 3) / pow(100, 3) + b * pow(i, 2) / pow(100, 2) + c * i / 100 + d;
        if (ans < 1e-6 && ans > -1e-6)
        {
            num[++pos] = i;
        }
    }
    cout << fixed << setprecision(2) << num[1] / 100.0 << " " << num[2] / 100.0 << " " << num[3] / 100.0;
    return 0;
}