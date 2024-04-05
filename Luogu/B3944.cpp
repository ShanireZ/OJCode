#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    long long k, a, q, mod = 722733748, ans = 1;
    cin >> k >> a >> q;
    for (int i = 1; i <= k; i++)
    {
        ans = ans * a % mod;
        a = a * q % mod;
    }
    cout << ans << endl;
    return 0;
}