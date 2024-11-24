#include <algorithm>
#include <iostream>
using namespace std;
long long n, a[200005], pre[200005], suf[200005];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        pre[i] = pre[i - 1];
        if (a[i] - a[i - 1] <= 0)
        {
            pre[i] += a[i - 1] - a[i] + 1;
        }
    }
    for (int i = n; i >= 1; i--)
    {
        suf[i] = suf[i + 1];
        if (a[i] - a[i + 1] <= 0)
        {
            suf[i] += a[i + 1] - a[i] + 1;
        }
    }
    long long ans = 8e18;
    for (int i = 1; i <= n; i++)
    {
        ans = min(ans, max(pre[i], suf[i]));
    }
    cout << ans << endl;
    return 0;
}