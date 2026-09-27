#include <algorithm>
#include <iostream>
using namespace std;
long long a, b, k, t, ans;
int main()
{
    cin >> a >> b >> k >> t;
    long long r = abs(a - b) / k, ex = abs(a - b) % k;
    long long res1 = r + ex, res2 = (r + 1) + (k - ex);
    ans = min(res1, res2);
    if (t == 2)
    {
        ans += 2;
        if (res1 != res2)
        {
            ans = min(ans, max(res1, res2));
        }
        if (r != 0)
        {
            ans = min(ans, res1 - 1 + k);
        }
    }
    cout << ans << endl;
    return 0;
}