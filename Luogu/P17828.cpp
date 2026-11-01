#include <algorithm>
#include <iostream>
using namespace std;
long long n, ans, a[200005];
char c[200005];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> c[i];
    }
    int l = 1, r = n;
    while (l < r)
    {
        int t = min(a[l], a[r]);
        if (c[l] != c[r])
        {
            ans += t;
        }
        a[l] -= t, a[r] -= t;
        if (a[l] == 0)
        {
            l++;
        }
        if (a[r] == 0)
        {
            r--;
        }
    }
    cout << ans << endl;
    return 0;
}