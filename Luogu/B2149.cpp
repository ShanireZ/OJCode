#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;
int main()
{
    double a, b, c;
    cin >> a >> b >> c;
    if (a + b > c && a + c > b && b + c > a)
    {
        double p = (a + b + c) / 2;
        cout << fixed << setprecision(2) << sqrt(p * (p - a) * (p - b) * (p - c));
    }
    else
    {
        cout << "No solution." << endl;
    }
    return 0;
}