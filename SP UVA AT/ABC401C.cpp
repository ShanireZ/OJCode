#include <algorithm>
#include <iostream>
using namespace std;
long long a[1000005];
int main()
{
    long long n, k, pre, mod = 1e9;
    cin >> n >> k;
    fill(a, a + k, 1), pre = k;
    for (int i = k; i <= n; i++)
    {
        a[i] = pre;
        pre = (pre + a[i] - a[i - k] + mod) % mod;
    }
    cout << a[n] << endl;
    return 0;
}