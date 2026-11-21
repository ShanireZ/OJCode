#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
long long a[1000005], cnt[1000005], now[1000005], lst[1000005], pre[1000005], n, ans;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        now[i] = now[i - 1] + (cnt[a[i]] == 0);
        cnt[a[i]]++;
        pre[i] = lst[a[i]];
        lst[a[i]] = i;
    }
    for (int i = n; i >= 1; i--)
    {
        if (cnt[a[i]] >= 2)
        {
            ans += now[pre[i] - 1] - (cnt[a[i]] > 2);
            cnt[a[i]] = 0;
        }
    }
    cout << ans << endl;
    return 0;
}