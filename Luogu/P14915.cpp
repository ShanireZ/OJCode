#include <algorithm>
#include <iostream>
using namespace std;
long long n, k, d, a[100005];
int main()
{
    cin >> n >> k >> d;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    long long pre = a[1], cnt = 1, ans = 0;
    for (int i = 2; i <= n; i++)
    {
        if (a[i] - pre <= d)
        {
            cnt++, pre = a[i];
            if (cnt == k && i == n)
            {
                break;
            }
            else if (cnt == k)
            {
                i++;
                cnt = 1, pre = a[i];
            }
        }
        else if (d == 0)
        {
            ans += k - cnt;
            cnt = 1, pre = a[i];
        }
        else
        {
            int delt = (a[i] - pre - 1) / d;
            if (k - cnt <= delt)
            {
                ans += k - cnt;
                cnt = 1, pre = a[i];
            }
            else
            {
                ans += delt, cnt += delt + 1, pre = a[i];
                if (cnt == k && i == n)
                {
                    break;
                }
                else if (cnt == k)
                {
                    i++;
                    cnt = 1, pre = a[i];
                }
            }
        }
    }
    cout << ans + (k - cnt) << endl;
    return 0;
}