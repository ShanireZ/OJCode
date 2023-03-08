#include <iostream>
using namespace std;
long long mod = 100000007, ans, st, ed, ex, n, k, res;
int main()
{
    cin >> n >> k;
    for (int i = n; i >= 1; i--)
    {
        st = st * 10 + ((i == n) ? 1 : 0);
        ex = ex * 10 + ((i == n) ? 9 : 0);
        ans = ans * 10 + ex / k;
        ans %= mod, ex %= k, st %= k;
    }
    st += 1, ed = st + ex - 1;
    res = (ed > k), ed -= res * k;
    for (int i = 1; i <= k; i++)
    {
        if ((res && i > ed && i < st) || (!res && (i > ed || i < st)))
        {
            cout << ans;
        }
        else
        {
            cout << (ans + 1) % mod;
        }
        cout << " ";
    }
    return 0;
}