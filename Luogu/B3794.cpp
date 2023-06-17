#include <iomanip>
#include <iostream>
using namespace std;
int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    double s = (a + c) * (b + c) - c * c, pi = 3.1415926535;
    s += pi * c * c / 4;
    cout << fixed << setprecision(3) << s / 10000 << endl;
    return 0;
}