#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
long long a[5005], n, m, pos, ans = 1;
int main()
{
    cin >> n >> m;
    for (int i = n; i > m; i--)
    {
        a[++pos] = i;
    }
    for (int i = 1; i <= n - m; i++) // 因数分解
    {
        long long x = i;
        for (int j = 1; j <= pos && x != 1; j++)
        {
            long long gc = __gcd(a[j], x);
            a[j] /= gc, x /= gc;
        }
    }
    for (int i = 1; i <= pos; i++)
    {
        ans = ans * a[i] % 1000000007;
    }
    cout << ans << endl;
    return 0;
}