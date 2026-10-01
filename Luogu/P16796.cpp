#include <algorithm>
#include <iostream>
using namespace std;
long long n, m, k, a[400005];
int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i + n] = a[i];
    }
    long long ans = 1;
    for (long long l = 1, r = 1, tot = 0; l <= n; l++)
    {
        r = max(r, l);
        while (r - l + 1 < n && tot + (abs(a[r + 1] - a[r]) > k) <= m)
        {
            r++;
            tot += (abs(a[r] - a[r - 1]) > k);
        }
        ans = max(ans, r - l + 1);
        if (l != r)
        {
            tot -= (abs(a[l + 1] - a[l]) > k);
        }
    }
    cout << ans << endl;
    return 0;
}