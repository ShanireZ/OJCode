#include <cmath>
#include <iostream>
using namespace std;
double countl(double x1, double y1, double x2, double y2)
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
double counts(double x1, double y1, double x2, double y2, double x3, double y3)
{
    double a = countl(x1, y1, x2, y2), b = countl(x2, y2, x3, y3), c = countl(x1, y1, x3, y3);
    double p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}
int main()
{
    double l, r, x1, x2, x3, y1, y2, y3;
    cin >> l >> r >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    double mins = 1e15;
    for (double p = l; p <= r; p += 0.00001)
    {
        double x4 = x1 + (x2 - x1) * p, y4 = y1 + (y2 - y1) * p;
        double x5 = x2 + (x3 - x2) * p, y5 = y2 + (y3 - y2) * p;
        double x6 = x3 + (x1 - x3) * p, y6 = y3 + (y1 - y3) * p;
        double s = counts(x4, y4, x5, y5, x6, y6);
        if (s < mins)
        {
            mins = s;
        }
    }
    cout << mins << endl;
    return 0;
}