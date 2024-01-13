#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
int n, k, ans, res, a[500005], b[500005], c[500005], p[500005];
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= k; i++)
    {
        cin >> a[i];
        p[a[i]] = i;
    }
    for (int i = 1; i <= k; i++)
    {
        cin >> b[i];
        if (p[b[i]] > 0)
        {
            int pos = (p[b[i]] - i + k) % k;
            c[pos]++;
            res = max(res, c[pos]);
        }
        else
        {
            p[b[i]] = -1;
        }
    }
    reverse(b + 1, b + k + 1);
    memset(c, 0, sizeof(c));
    for (int i = 1; i <= k; i++)
    {
        if (p[b[i]] > 0)
        {
            int pos = (p[b[i]] - i + k) % k;
            c[pos]++;
            res = max(res, c[pos]);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        ans += (p[i] == 0);
    }
    cout << ans + res << endl;
    return 0;
}