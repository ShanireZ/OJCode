#include <algorithm>
#include <iostream>
using namespace std;
int a[100005];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    int l = 1, r = n;
    while ((l - 1) + (n - (r - 1)) + min(l - 1, n - (r - 1)) <= m && r > l)
    {
        r--;
    }
    int ans = a[r] - a[l];
    while (l < r)
    {
        l++;
        while ((l - 1) + (n - r) + min(l - 1, n - r) > m && r < n)
        {
            r++;
        }
        if ((l - 1) + (n - r) + min(l - 1, n - r) > m)
        {
            break;
        }
        ans = min(ans, a[r] - a[l]);
    }
    cout << ans << endl;
    return 0;
}