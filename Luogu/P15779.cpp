#include <algorithm>
#include <iostream>
using namespace std;
long long T, n, a[5], b[5], cnt[5], ex[5];
int main()
{
    cin >> T;
    while (T--)
    {
        cin >> n;
        for (int i = 1; i <= 3; i++)
        {
            cin >> a[i] >> b[i];
        }
        long long l = 1, r = 1e18;
        while (l <= r)
        {
            long long mid = (l + r) / 2; // 单次最大花费限制
            long long sum = 0;
            for (int j = 1; j <= 3; j++)
            {
                cnt[j] = (mid < a[j] ? 0 : (mid - a[j]) / b[j] + 1);
                sum += cnt[j];
            }
            sum > n ? r = mid - 1 : l = mid + 1;
        }
        long long ans = 0, sum = 0, lmt = r;
        for (int j = 1; j <= 3; j++)
        {
            cnt[j] = (lmt < a[j] ? 0 : (lmt - a[j]) / b[j] + 1);
            sum += cnt[j];
            if (cnt[j])
            {
                ans += (a[j] + a[j] + b[j] * (cnt[j] - 1)) * cnt[j] / 2;
            }
        }
        while (n != sum)
        {
            long long mn = 1;
            for (int j = 1; j <= 3; j++)
            {
                ex[j] = a[j] + b[j] * cnt[j];
                if (ex[j] < ex[mn])
                {
                    mn = j;
                }
            }
            ans += ex[mn], cnt[mn]++, sum++;
        }
        cout << ans << endl;
    }
    return 0;
}