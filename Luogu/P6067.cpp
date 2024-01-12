#include <algorithm>
#include <iostream>
using namespace std;
long long a[100005], n, ans, pre, suf;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        suf += a[i];
    }
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++)
    {
        ans += (i - 1) * a[i] - pre;
        ans += suf - (n - i + 1) * a[i];
        pre += a[i], suf -= a[i];
    }
    cout << ans << endl;
    return 0;
}
// TAG: 模拟 枚举 贪心 前缀和 后缀和