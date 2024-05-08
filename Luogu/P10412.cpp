#include <algorithm>
#include <iostream>
using namespace std;
long long a[100005], n, p, q, r, tot, ans;
int main()
{
    cin >> n >> p >> q >> r;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        tot += a[i];
    }
    sort(a + 1, a + n + 1);
    // 美妙的前提条件是数列和为非负数,不然肯定后续会不美妙
    for (int i = 1; i <= n && tot < 0; i++)
    {
        long long delt = min(-a[i], -tot); // 判断是否需要整体进行操作1
        if (i == n)                        // 题目要求数列不能删空,所以如果都是负数,最大那个要进行操作1
        {
            ans += delt * p;
        }
        else
        {
            ans += min(delt * p, q);
        }
        tot -= a[i];
    }
    cout << ans << endl;
    return 0;
}