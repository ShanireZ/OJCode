#include <algorithm>
#include <iostream>
using namespace std;
long long a[200005], n, tot;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        tot += a[i];
    }
    long long minv = a[1], maxv = a[1], sum1 = a[1], sum2 = a[1];
    for (int i = 2; i <= n; i++)
    {
        sum1 > 0 ? sum1 += a[i] : sum1 = a[i];
        maxv = max(maxv, sum1);
        sum2 < 0 ? sum2 += a[i] : sum2 = a[i];
        minv = min(minv, sum2);
    }
    long long ans = maxv;
    if (tot != minv)
    {
        ans = max(ans, tot - minv);
    }
    cout << ans << endl;
    return 0;
}