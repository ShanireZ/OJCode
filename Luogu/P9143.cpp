#include <algorithm>
#include <iostream>
using namespace std;
long long t[100005], maxn[100005];
// t[x]出现x次的数字个数,差分进行统计   maxn[x]出现x次的最大数字
int main()
{
    long long n, maxt = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        long long x;
        cin >> x;
        maxt = max(maxt, x);
        t[1]++, t[x + 1]--, maxn[x] = i;
    }
    for (int i = 1; i <= maxt; i++)
    {
        t[i] += t[i - 1];
    }
    long long ans = 0, pre = 0;
    for (int i = maxt; i >= 1; i--)
    {
        if (maxn[i] == 0 || maxn[i] < pre)
        {
            ans += t[i] * pre;
        }
        else if (maxn[i] > pre)
        {
            ans += t[i] * maxn[i], pre = maxn[i];
        }
    }
    cout << ans << "\n";
    return 0;
}