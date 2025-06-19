#include <algorithm>
#include <iostream>
using namespace std;
long long n, k, s, t, ans, a[100005], b[100005], c[100005];
int main()
{
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        cin >> a[i];
    }
    cin >> k;
    for (int i = 1; i <= k; i++)
    {
        cin >> b[i];
    }
    for (int i = 1; i <= k; i++)
    {
        long long x;
        cin >> x;
        c[b[i]] = x;
    }
    cin >> s >> t;
    for (int i = s; i < t; i++)
    {
        ans += a[i] + c[i];
    }
    cout << ans - c[s] << endl;
    return 0;
}