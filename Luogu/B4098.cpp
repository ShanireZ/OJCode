#include <algorithm>
#include <iostream>
using namespace std;
int a[1000005], cnt[2005], ans = 1e9, n, m, sum;
int main()
{
    cin >> n >> m;
    for (int i = 1, l = 1; i <= n; i++)
    {
        cin >> a[i];
        if (++cnt[a[i]] == 1)
        {
            sum++;
        }
        while (sum == m)
        {
            ans = min(ans, i - l + 1);
            if (--cnt[a[l++]] == 0)
            {
                sum--;
            }
        }
    }
    cout << ans * 10 << endl;
    return 0;
}