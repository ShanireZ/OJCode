#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    long long ans = -1e9, sum = 0, n, a;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        sum = a + (sum > 0) * sum;
        ans = max(ans, sum);
    }
    printf("%lld", ans);
    return 0;
}