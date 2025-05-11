#include <algorithm>
#include <iostream>
using namespace std;
long long ans, n, a[300005], hz[300005];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        hz[i] = a[i];
    }
    for (int i = n; i >= 1; i--)
    {
        hz[i] += hz[i + 1];
        ans += a[i] * hz[i + 1];
    }
    cout << ans << endl;
    return 0;
}