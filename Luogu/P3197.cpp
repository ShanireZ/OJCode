#include <iostream>
using namespace std;
long long mod = 1e5 + 3;
long long make(long long a, long long b) //a^b快速幂
{
    long long ans = 1;
    a %= mod;
    b %= mod - 1; //欧拉降幂
    while (b)
    {
        if (b & 1)
        {
            ans = ans * a % mod;
        }
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}
int main()
{
    long long m, n;
    cin >> m >> n;
    //有可能出负数 需要转正
    cout << ((make(m, n) - make(m - 1, n - 1) * m % mod) + mod) % mod;
    return 0;
}