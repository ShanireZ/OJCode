#include <algorithm>
#include <iostream>
using namespace std;
int a[100005];
int main()
{
    int n, ans = 1;
    cin >> n >> a[1];
    for (int i = 2; i <= n; i++)
    {
        int x;
        cin >> x;
        int now = upper_bound(a + 1, a + 1 + ans, x) - a;
        if (now == ans + 1)
        {
            ans++;
        }
        a[now] = x;
    }
    cout << ans << endl;
    return 0;
}