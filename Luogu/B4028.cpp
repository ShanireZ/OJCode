#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    long long n;
    double m;
    cin >> n >> m;
    m /= 100;
    long long s = (1 + n) * n / 2;
    for (int i = 1; i <= n; i++)
    {
        double x = 1.0 * i / s;
        if (x >= m)
        {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}