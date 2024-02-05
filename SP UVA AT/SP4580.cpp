#include <algorithm>
#include <iostream>
using namespace std;
long long nums[105], fa[1000005], n, pos, ans;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> nums[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= n; k++)
            {
                fa[pos++] = nums[i] * nums[j] + nums[k];
            }
        }
    }
    sort(fa, fa + pos);
    for (int i = 1; i <= n; i++)
    {
        if (nums[i] == 0)
        {
            continue;
        }
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= n; k++)
            {
                long long tot = nums[i] * (nums[j] + nums[k]);
                long long p1 = lower_bound(fa, fa + pos, tot) - fa;
                if (fa[p1] == tot)
                {
                    long long p2 = upper_bound(fa, fa + pos, tot) - fa;
                    ans += p2 - p1;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
// TAG: 双向搜索 meet in the middle