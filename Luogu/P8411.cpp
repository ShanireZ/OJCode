#include <iostream>
#include <vector>
using namespace std;
typedef unsigned int uint;
uint a[10000005], fa[10000005], seed, n;
inline uint get_next(uint &sd)
{
    sd ^= sd << 13;
    sd ^= sd >> 17;
    sd ^= sd << 5;
    return sd;
}
int main()
{
    cin >> n >> seed;
    for (register uint i = 1; i <= n; i++)
    {
        a[i] = get_next(seed);
    }
    for (register uint i = 2; i <= n; i++)
    {
        fa[i] = get_next(seed) % (i - 1) + 1;
    }
    long long ans = a[1];
    for (register uint i = 2; i <= n; i++)
    {
        a[i] = min(a[i], a[fa[i]]);
        ans += a[i];
    }
    cout << ans << endl;
    return 0;
}