#include <cmath>
#include <iostream>
using namespace std;
int main()
{
    long long n, x, p, q;
    cin >> n >> x >> p >> q;
    long long cost = 0, d = 1, today = 0;
    for (int i = 1; i <= n; i++)
    {
        long long t;
        cin >> t;
        if (d * x * (q - p) < (cost + t) * q)
        {
            d = ceil(1.0 * (cost + t) * q / (q - p) / x), today = 0;
        }
        if (today + t >= x)
        {
            d++, today = 0;
        }
        cost += t, today += t;
    }
    cout << d << endl;
    return 0;
}