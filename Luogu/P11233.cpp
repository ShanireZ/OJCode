#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
int pre[200005], a[200005], lst[1000005], T, n, pos, x;
long long dp[200005], res;
int main()
{
    cin >> T;
    while (T--)
    {
        memset(lst, 0, sizeof(lst)), memset(pre, 0, sizeof(pre));
        memset(a, 0, sizeof(a)), memset(dp, 0, sizeof(dp));
        pos = res = 0;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> x;
            (x != a[pos]) ? (a[++pos] = x, pre[pos] = lst[x], lst[x] = pos) : (res += x);
        }
        for (int i = 2; i <= pos; i++)
        {
            // a[i]和a[pre[i]]同色才能加分a[i]
            // a[pre[i] + 1]必和他们颜色不同,且如果也能加分那么可以产生更大的分数
            dp[i] = (pre[i] ? max(dp[i - 1], dp[pre[i] + 1] + a[i]) : dp[i - 1]);
        }
        cout << res + dp[pos] << endl;
    }
    return 0;
}