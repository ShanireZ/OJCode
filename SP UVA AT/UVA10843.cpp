#include <algorithm>
#include <iostream>
using namespace std;
long long t, n, mod = 2000000011;
int main()
{
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cin >> n;
        long long ans = 1, base = n, pw = n - 2;
        while (pw)
        {
            if (pw % 2 == 1)
            {
                ans = (ans * base) % mod;
            }
            base = (base * base) % mod, pw /= 2;
        }
        cout << "Case #" << i << ": " << ans << endl;
    }
    return 0;
}