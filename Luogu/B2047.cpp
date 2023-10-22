#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;
int main()
{
    double x, y;
    cin >> x;
    if (x < 5)
    {
        y = -x + 2.5;
    }
    else if (x < 10)
    {
        y = 2 - 1.5 * (x - 3) * (x - 3);
    }
    else
    {
        y = x / 2 - 1.5;
    }
    cout << fixed << setprecision(3) << y << endl;
    return 0;
}