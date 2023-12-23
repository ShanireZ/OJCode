#include <algorithm>
#include <iostream>
using namespace std;
long long a[100], jc[100], p2[100], mod = 1e9 + 7;
int bx[100];
void init()
{
    p2[0] = jc[0] = 1;
    for (int i = 1; i <= 61; i++)
    {
        p2[i] = p2[i - 1] * 2;
        jc[i] = jc[i - 1] * i % mod;
    }
}
int main()
{
    init();
    long long n, x;
    cin >> n >> x;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    if (a[n] + a[1] > x) // 无法安排
    {
        cout << 0 << endl;
        return 0;
    }
    else if (a[n] + a[n - 1] <= x) // 随便安排
    {
        cout << jc[n] << endl;
        return 0;
    }
    int h1 = -1, h2 = -1;
    for (long long i = 0, tmp = x; tmp != 0; i++, tmp /= 2)
    {
        if (tmp % 2 == 1)
        {
            h2 = h1;
            h1 = i;
        }
    }
    int k = upper_bound(a + 1, a + 1 + n, p2[h2]) - a - 1;   // 能和a[n]配对的数的个数
    long long ans = jc[n - 2] * (k * 2 + k * (k - 1)) % mod; // a[n]可以放两头或者中间
    cout << ans << endl;
    return 0;
}