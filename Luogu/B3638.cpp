#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
int main()
{
    long long x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    double a = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    double b = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2));
    double c = sqrt(pow(x2 - x3, 2) + pow(y2 - y3, 2));
    double s = (a + b + c) / 2;
    cout << (long long)round(sqrt(s * (s - a) * (s - b) * (s - c))) << endl;
    return 0;
}