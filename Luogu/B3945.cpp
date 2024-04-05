#include <algorithm>
#include <iostream>
using namespace std;
long long a[100005], n, q, v, ans;
int main()
{
    cin >> n >> q >> v;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= q; i++)
    {
        long long x, y;
        cin >> x >> y;
        a[x] = y;
    }
    for (int i = 1; i <= n; i++)
    {
        ans += (a[i] >= v);
    }
    cout << ans << endl;
    return 0;
}