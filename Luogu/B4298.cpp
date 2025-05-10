#include <algorithm>
#include <iostream>
using namespace std;
int n, k, ans = 1e9, a[10005], b[10005];
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (i >= k)
        {
            for (int j = 1; j <= k; j++)
            {
                b[j] = a[i - j + 1];
            }
            nth_element(b + 1, b + k / 2 + 1, b + 1 + k);
            int m = b[k / 2 + 1], tot = 0;
            for (int j = 1; j <= k; j++)
            {
                tot += abs(b[j] - m);
            }
            ans = min(ans, tot);
        }
    }
    cout << ans << endl;
    return 0;
}