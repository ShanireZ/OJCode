#include <algorithm>
#include <iostream>
using namespace std;
long long ans, h[1000005], l[1000005];
int main()
{
    ios::sync_with_stdio(false);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= k; i++) // 枚舉所有因數
    {
        for (int j = i; j <= k; j += i) // 枚舉包含當前因數的數
        {
            h[j] += (i <= n), l[j] += (i <= m); // k=j時統計行列的選擇情況
        }
    }
    for (int i = 1; i <= k; i++)
    {
        ans += h[i] * l[i] * i;
    }
    cout << ans << endl;
    return 0;
}