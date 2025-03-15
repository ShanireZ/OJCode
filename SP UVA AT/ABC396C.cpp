#include <algorithm>
#include <iostream>
using namespace std;
long long b[200005], w[200005], n, m, ans;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> w[i];
    }
    sort(b + 1, b + 1 + n, greater<long long>());
    sort(w + 1, w + 1 + m, greater<long long>());
    long long sum = 0, p1 = 1, p2 = 1;
    while (b[p1] >= 0 && p1 <= n)
    {
        sum += b[p1++];
    }
    while (w[p2] >= 0 && p2 <= m && p2 < p1)
    {
        sum += w[p2++];
    }
    ans = max(ans, sum);
    while (p1 <= n && p2 <= m && w[p2] > 0)
    {
        sum += w[p2++];
        if (p2 > p1)
        {
            sum += b[p1++];
        }
        ans = max(ans, sum);
    }
    cout << ans << endl;
    return 0;
}