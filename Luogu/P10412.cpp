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
    // 美妙的前提條件是數列和為非負數,不然肯定後續會不美妙
    for (int i = 1; i <= n && tot < 0; i++)
    {
        long long delt = min(-a[i], -tot); // 判斷是否需要整體進行操作1
        if (i == n)                        // 題目要求數列不能刪空,所以如果都是負數,最大那個要進行操作1
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