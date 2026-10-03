#include <algorithm>
#include <iostream>
using namespace std;
long long n, k, lst, ans, now = 1, sum[100005];
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        long long l, r;
        cin >> l >> r;
        sum[i] = sum[i - 1];
        if (l > lst)
        {
            sum[i] += l - lst;
        }
        lst = max(lst, r);
    }
    while (k--)
    {
        int nxt;
        cin >> nxt;
        ans += abs(sum[nxt] - sum[now]);
        now = nxt;
    }
    cout << ans << endl;
    return 0;
}