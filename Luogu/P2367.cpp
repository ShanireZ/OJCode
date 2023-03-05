#include <iostream>
using namespace std;
#define MX 5000005
int a[MX], d[MX];
int main()
{
    int n, p, ans = 0x3f3f3f3f;
    cin >> n >> p;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        d[i] = a[i] - a[i - 1];
    }
    for (int i = 1; i <= p; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        d[x] += z, d[y + 1] -= z;
    }
    for (int i = 1; i <= n; i++)
    {
        a[i] = a[i - 1] + d[i];
        ans = min(ans, a[i]);
    }
    cout << ans << "\n";
    return 0;
}