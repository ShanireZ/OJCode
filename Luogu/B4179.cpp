#include <algorithm>
#include <iostream>
using namespace std;
long long ans, k, n, p[100005], c[100005];
int main()
{
    cin >> k >> n;
    if (k >= n)
    {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
    }
    sort(p + 1, p + n + 1);
    for (int i = 2; i <= n; i++)
    {
        c[i] = p[i] - p[i - 1];
    }
    sort(c + 2, c + n + 1);
    for (int i = 2, cnt = n - k; i <= n && cnt; i++, cnt--)
    {
        ans += c[i];
    }
    cout << ans << endl;
    return 0;
}