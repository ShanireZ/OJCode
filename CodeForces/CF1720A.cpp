#include <iostream>
using namespace std;
long long gcd(long long x, long long y)
{
    long long r = x % y;
    while (r)
    {
        x = y;
        y = r;
        r = x % y;
    }
    return y;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long a, b, c, d;
        cin >> a >> b >> c >> d;
        a = a * d, b = b * c;
        if (a == b)
        {
            cout << 0 << endl;
        }
        else
        {
            if (b == 0)
            {
                swap(a, b);
            }
            long long x = gcd(a, b);
            a /= x, b /= x;
            if (a == 1 || b == 1)
            {
                cout << 1 << endl;
            }
            else
            {
                cout << 2 << endl;
            }
        }
    }
    return 0;
}