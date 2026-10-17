#include <algorithm>
#include <iostream>
using namespace std;
int n, ans, a[1005];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1, greater<int>());
    for (int i = 1; i <= n; i++)
    {
        a[i] += a[i - 1];
        ans += a[i];
    }
    cout << ans << endl;
    return 0;
}