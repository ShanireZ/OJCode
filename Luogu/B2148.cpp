#include <algorithm>
#include <iostream>
#include <iomanip>
using namespace std;
double f(double x, int n)
{
    if (n == 0)
    {
        return x;
    }
    return x / (n + f(x, n - 1));
}
int main()
{
    double x;
    int n;
    cin >> x >> n;
    cout << fixed << setprecision(2) << f(x, n) << endl;
    return 0;
}