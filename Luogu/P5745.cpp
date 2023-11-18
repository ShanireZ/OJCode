#include <algorithm>
#include <iostream>
using namespace std;
long long a[4000005], n, m;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    long long l = 0, r = 0, now = 0, ans = 0, ansl = 0, ansr = 0;
    while (l <= n && r <= n)
    {
        while (r <= n && now + a[r + 1] <= m)
        {
            now += a[++r];
        }
        if (now <= m && now > ans)
        {
            ans = now, ansl = l, ansr = r;
        }
        now -= a[l++];
    }
    cout << ansl << " " << ansr << " " << ans << endl;
    return 0;
}