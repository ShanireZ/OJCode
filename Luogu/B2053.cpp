#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;
int main()
{
    double a, b, c;
    cin >> a >> b >> c;
    double delta = b * b - 4 * a * c;
    if (delta < 0)
    {
        cout << "No answer!\n";
    }
    else if (delta == 0)
    {
        cout << "x1=x2=";
        cout << fixed << setprecision(5) << -b / (a + a) << endl;
    }
    else
    {
        double x1 = (-b + sqrt(delta)) / (a + a);
        double x2 = (-b - sqrt(delta)) / (a + a);
        if (x2 < x1)
        {
            swap(x1, x2);
        }
        cout << fixed << setprecision(5) << "x1=" << x1 << ";x2=" << x2 << endl;
    }
    return 0;
}