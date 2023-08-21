#include <iomanip>
#include <iostream>
using namespace std;
int main()
{
    double c, i, g, m, x;
    cin >> c >> i >> g >> m >> x;
    cout << fixed << setprecision(2) << c + i + g - m + x;
    return 0;
}