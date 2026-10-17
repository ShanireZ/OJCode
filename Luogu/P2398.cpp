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
// 設 f[i] 表示 gcd=i 的數對個數
// 設 g[i] 表示 gcd=i*k 的數對個數 k∈[1,n/i]  (n/i向下取整)
// 則必然有 g[i] = f[i] + f[2*i] + f[3*i] + ... + f[n/i*i]
// 同樣必然有 g[i] = (n / i) * (n / i) ，因為數對的第一個數和第二個數都有 n/i 個選擇
// 所以 f[i] = (n / i) * (n / i) - f[2*i] - f[3*i] - ... - f[n/i*i]
// 複雜度 n / 1 + n / 2 + n / 3 + ... + n / n = n * 調和級數 = n * ln(n)