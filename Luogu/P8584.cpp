#include <iostream>
#include <cmath>
using namespace std;
long long gcd(long long a, long long b)
{
    long long r = a % b;
    while (r)
    {
        a = b;
        b = r;
        r = a % b;
    }
    return abs(b);
}
long long lcm(long long a, long long b)
{
    long long c = a * b;
    return abs(c / gcd(a, b));
}
int main()
{
    int n;
    cin >> n;
    long long a = 0, b = 1, s = 0;
    for (int i = 1; i <= n; i++)
    {
        long long x, y, op, st;
        cin >> x >> y >> op;
        st = x / y, x %= y;
        long long k = lcm(b, y);
        if (op == 1)
        {
            a = a * k / b + x * k / y;
            b = k, s += st;
        }
        else
        {
            a = a * k / b - x * k / y;
            b = k, s -= st;
        }
        s += a / b, a %= b;
        k = gcd(a, b);
        a /= k, b /= k;
    }
    cout << s * b + a;
    if (b != 1)
    {
        cout << "/" << b << endl;
    }
    return 0;
}