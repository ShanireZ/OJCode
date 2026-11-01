#include <algorithm>
#include <iostream>
using namespace std;
#define MX 500005
long long n, m, ans, a[500005];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    long long l = 1, r = 1, cost = 0;
    while (l <= n)
    {
        r = max(r, l);
        while (r < n && cost + (a[r + 1] - a[r]) * (r - l + 1) <= m)
        {
            cost += (a[r + 1] - a[r]) * (r - l + 1);
            r++;
        }
        ans = max(ans, r - l + 1);
        cost -= (a[r] - a[l]);
        l++;
    }
    cout << ans << endl;
    return 0;
}