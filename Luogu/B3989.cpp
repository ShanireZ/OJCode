#include <algorithm>
#include <iostream>
using namespace std;
int a[1005];
int main()
{
    int n, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        ans += a[i];
    }
    sort(a + 1, a + n + 1);
    int tot = 0;
    for (int i = n, c = n - 1; i >= 1; i--, c--)
    {
        tot += a[i];
        if (tot >= c)
        {
            cout << ans - (i - 1) << endl;
            return 0;
        }
    }
    return 0;
}