#include <algorithm>
#include <iostream>
using namespace std;
int a[100005];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    int ans = 0x3f3f3f3f;
    for (int i = 1; i <= n - m + 1; i++)
    {
        ans = min(ans, a[i + m - 1] - a[i]);
    }
    cout << ans << "\n";
    return 0;
}