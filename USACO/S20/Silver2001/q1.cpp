#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;
int b[1005];
int mod;
bool cmp(int a, int b) //!按照%mod的值从大到小排序
{
    return a % mod > b % mod;
}
int main()
{
    // freopen("berries.in", "r", stdin);
    // freopen("berries.out", "w", stdout);
    int n, k, maxb = 0;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
        maxb = max(maxb, b[i]);
    }
    int ans = 0;
    for (int i = 1; i <= maxb; i++)
    {
        int cnt = 0; //!能摘几个篮子的i
        for (int j = 1; j <= n; j++)
        {
            cnt += b[j] / i;
        }
        if (cnt >= k) //!如果 妹妹够k/2 自己够k/2
        {
            ans = max(ans, k / 2 * i);
        }
        else if (cnt < k && cnt >= k / 2) //!如果 妹妹够k/2 自己不够k/2
        {
            mod = i;
            sort(b + 1, b + 1 + n, cmp);
            int sum = (cnt - k / 2) * i;       //!自己能摘几个i
            for (int j = 1; j <= k - cnt; j++) //!剩下的篮子能摘几个摘几个
            {
                sum += b[j] % mod;
            }
            ans = max(ans, sum);
        }
        else if (cnt < k / 2) //!摘不够k/2个
        {
            break;
        }
    }
    cout << ans;
    return 0;
}