#include <algorithm>
#include <iostream>
using namespace std;
long long dp[2], a[200005], b[200005], n;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    for (int i = 2; i <= n; i++)
    {
        long long va = min(dp[0] + abs(a[i] - a[i - 1]), dp[1] + abs(a[i] - b[i - 1]));
        long long vb = min(dp[0] + abs(b[i] - a[i - 1]), dp[1] + abs(b[i] - b[i - 1]));
        dp[0] = va, dp[1] = vb;
    }
    cout << min(dp[0], dp[1]) << endl;
    return 0;
}