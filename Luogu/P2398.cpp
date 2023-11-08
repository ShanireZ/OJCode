#include <iostream>
using namespace std;
long long f[100005], ans, n;
int main()
{
    cin >> n;
    for (int i = n; i >= 1; i--)
    {
        f[i] = (n / i) * (n / i);
        for (int j = i + i; j <= n; j += i)
        {
            f[i] -= f[j];
        }
        ans += f[i] * i;
    }
    cout << ans << endl;
    return 0;
}
// 设 f[i] 表示 gcd=i 的数对个数
// 设 g[i] 表示 gcd=i*k 的数对个数 k∈[1,n/i]  (n/i向下取整)
// 则必然有 g[i] = f[i] + f[2*i] + f[3*i] + ... + f[n/i*i]
// 同样必然有 g[i] = (n / i) * (n / i) ，因为数对的第一个数和第二个数都有 n/i 个选择
// 所以 f[i] = (n / i) * (n / i) - f[2*i] - f[3*i] - ... - f[n/i*i]
// 复杂度 n / 1 + n / 2 + n / 3 + ... + n / n = n * 调和级数 = n * ln(n)