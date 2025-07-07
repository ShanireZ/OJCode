#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
int main()
{
    long long n, m, a, b;
    cin >> n >> m >> a >> b;
    if (a == b)
    {
        cout << min(n, m) / a << endl;
        return 0;
    }
    if (a > b)
    {
        swap(a, b);
    }
    long long t1 = min(n / a, m / b), t2 = min(n / b, m / a);
    long long l = max(min((n - t1 * a) / b, (m - t1 * b) / a) + t1,
                      min((n - t2 * a) / b, (m - t2 * b) / a) + t2);
    long long r = (n + m) / (a + b);
    while (l <= r)
    {
        long long mid = (l + r) / 2;
        long long x = ceil(1.0 * (b * mid - n) / (b - a));
        long long y = floor(1.0 * (m - a * mid) / (b - a));
        x = max(x, 0ll), y = min(y, mid);
        x <= y ? l = mid + 1 : r = mid - 1;
    }
    cout << r << endl;
    return 0;
}