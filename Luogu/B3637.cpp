#include <algorithm>
#include <iostream>
using namespace std;
int dp[5005], a[5005], pos = 0;
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        int p = lower_bound(dp + 1, dp + 1 + pos, a[i]) - dp;
        dp[p] = a[i], pos = max(pos, p);
    }
    cout << pos << endl;
    return 0;
}