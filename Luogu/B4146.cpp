#include <algorithm>
#include <iostream>
using namespace std;
int a[5005], n, k, ans;
int main()
{
    cin >> n >> k;
    int l = n - k + 1, cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        cnt += (a[i] <= 49);
        if (i > l)
        {
            cnt += (a[i] > 49 && a[i] <= 51);
        }
    }
    for (int i = l; i >= 1; i--)
    {
        cnt = cnt + (a[i] > 49 && a[i] <= 51) - (a[i + k] > 49 && a[i + k] <= 51);
        ans += (cnt > n / 2);
    }
    cout << ans << endl;
    return 0;
}