#include <algorithm>
#include <iostream>
using namespace std;
long long a[200005], w, n, m, ans, res, pos;
int main()
{
    cin >> n >> m >> w;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        res += a[i];
    }
    sort(a + 1, a + n + 1);
    ans = res, pos = n;
    for (int i = 1; pos; i++)
    {
        res += w;
        for (int j = 1; j <= m && pos; j++, pos--)
        {
            res -= a[pos];
        }
        ans = min(ans, res);
    }
    cout << ans << endl;
    return 0;
}