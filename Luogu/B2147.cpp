#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;
double f(double x, int n)
{
    if (n == 0)
    {
        return x;
    }
    return sqrt(n + f(x, n - 1));
}
int main()
{
    int n;
    double x;
    cin >> x >> n;
    cout << fixed << setprecision(2) << f(x, n) << endl;
    return 0;
}