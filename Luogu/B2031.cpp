#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;
int main()
{
    double x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    double b1 = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    double b2 = sqrt((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3));
    double b3 = sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2));
    double p = (b1 + b2 + b3) / 2;
    cout << fixed << setprecision(2) << sqrt(p * (p - b1) * (p - b2) * (p - b3)) << endl;
    return 0;
}