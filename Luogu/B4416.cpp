#include <algorithm>
#include <iostream>
using namespace std;
int n, ans = 1, a[100005];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 2, pre = a[1], cnt = 1; i <= n; i++)
    {
        if (a[i] == pre)
        {
            continue;
        }
        cnt = (pre + 1 == a[i] ? cnt + 1 : 1);
        pre = a[i], ans = max(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}