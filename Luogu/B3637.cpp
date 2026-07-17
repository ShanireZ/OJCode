#include <algorithm>
#include <iostream>
using namespace std;
int dp[5005], n, lst, a;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        int p = lower_bound(dp + 1, dp + 1 + lst, a) - dp;
        dp[p] = a, lst = max(lst, p);
    }
    cout << lst << endl;
    return 0;
}