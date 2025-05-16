#include <algorithm>
#include <iostream>
using namespace std;
long long p = 1145141, ans, qz[1000005], inv[1145146];
int main()
{
    int n, q;
    cin >> n >> q;
    qz[0] = inv[1] = 1;
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        qz[i] = qz[i - 1] * a % p;
    }
    for (int i = 2; i < p; i++)
    {
        inv[i] = (p - p / i) * inv[p % i] % p;
    }
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        ans ^= qz[r] * inv[qz[l - 1]] % p;
    }
    cout << ans << endl;
    return 0;
}