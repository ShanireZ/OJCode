#include <algorithm>
#include <iostream>
using namespace std;
long long t, n, k, a;
int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        __int128 lcm = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> a;
            if (k % a == 0)
            {
                lcm = (lcm == 0 ? a : lcm / __gcd(lcm, (__int128)a) * a);
            }
        }
        cout << (lcm == k ? "Yes" : "No") << endl;
    }
    return 0;
}