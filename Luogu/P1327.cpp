#include <algorithm>
#include <iostream>
using namespace std;
long long a[100005], b[100005], p[100005], n, ans;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b + 1, b + n + 1);
    for (int i = 1; i <= n; i++)
    {
        a[i] = lower_bound(b + 1, b + n + 1, a[i]) - b;
        p[a[i]] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == i)
        {
            continue;
        }
        ans++;
        p[a[i]] = p[i];
        swap(a[i], a[p[i]]);
    }
    cout << ans << endl;
    return 0;
}
// TAG: 模拟 贪心 离散化