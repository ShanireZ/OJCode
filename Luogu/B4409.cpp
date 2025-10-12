#include <algorithm>
#include <iomanip>
#include <iostream>
using namespace std;
int main()
{
    int x, y, n, p;
    cin >> x >> y >> n >> p;
    double a = p - 1.0 * y * (p >= x);
    double b = p * n / 10.0;
    cout << fixed << setprecision(2) << min(a, b) << endl;
    return 0;
}