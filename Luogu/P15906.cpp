#include <algorithm>
#include <iostream>
using namespace std;
long long n, ans, r[300005], b[300005];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> r[i];
        ans += abs(r[i]);
        b[i] = r[i] >= 0 ? r[i] : r[i] * 3; // 被蓝色法术覆盖时贡献的变化值
    }
    long long mx = 0, now = 0;
    for (int i = 1; i <= n; i++)
    {
        now + b[i] >= 0 ? now += b[i] : now = 0;
        mx = max(mx, now);
    }
    cout << ans + mx << endl;
    return 0;
}