#include <algorithm>
#include <iostream>
using namespace std;
struct Node
{
    int nums, len;
};
Node zd, cd;
int n, a, ans, lst[500005], dp[500005][3]; // [x][1]:x作为第一个 [x][2]:x作为第二个
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        if (lst[a] != 0)
        {
            dp[i][2] = dp[lst[a]][1] + 2;
        }
        dp[i][1] = (zd.nums != a ? zd.len : cd.len);
        ans = max(ans, dp[i][2]), lst[a] = i;
        if (dp[i][2] >= zd.len)
        {
            if (a == zd.nums)
            {
                zd.len = dp[i][2];
            }
            else
            {
                cd = zd;
                zd = Node{a, dp[i][2]};
            }
        }
        else if (dp[i][2] >= cd.len)
        {
            cd = Node{a, dp[i][2]};
        }
    }
    cout << ans << endl;
    return 0;
}