#include <algorithm>
#include <iostream>
using namespace std;
long long a[200005], c[200005], ans;
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        c[i] = c[i - 1] + a[i];
    }
    for (int i = 1; i < n; i++)
    {
        ans += a[i] * (c[n] - c[i]);
    }
    cout << ans << endl;
    return 0;
}