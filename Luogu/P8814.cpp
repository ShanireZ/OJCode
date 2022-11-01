#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, e, d;
        cin >> n >> e >> d;
        long long sum = n - e * d + 2;
        long long l = 1, r = sum / 2, t = 0;
        while (l <= r)
        {
            long long p = (l + r) / 2;
            long long q = sum - p;
            if (p * q == n)
            {
                cout << p << " " << q << endl;
                t = 1;
                break;
            }
            else if (p * q > n)
            {
                r = p - 1;
            }
            else
            {
                l = p + 1;
            }
        }
        if (t == 0)
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}