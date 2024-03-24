#include <algorithm>
#include <iostream>
using namespace std;
long long ans, h[1000005], l[1000005];
int main()
{
    ios::sync_with_stdio(false);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= k; i++) // 枚举所有因数
    {
        for (int j = i; j <= k; j += i) // 枚举包含当前因数的数
        {
            h[j] += (i <= n), l[j] += (i <= m); // k=j时统计行列的选择情况
        }
    }
    for (int i = 1; i <= k; i++)
    {
        ans += h[i] * l[i] * i;
    }
    cout << ans << endl;
    return 0;
}