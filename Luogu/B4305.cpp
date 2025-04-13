#include <algorithm>
#include <iostream>
using namespace std;
int a[1005], n, k;
int main()
{
    cin >> n;
    int l = 0, r = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        l = max(l, a[i]), r += a[i];
    }
    cin >> k;
    while (l <= r)
    {
        int mid = (l + r) / 2, cnt = 1, tot = 0;
        for (int i = 1; i <= n; i++)
        {
            if (tot + a[i] > mid)
            {
                cnt++, tot = a[i];
            }
            else
            {
                tot += a[i];
            }
        }
        cnt <= k ? r = mid - 1 : l = mid + 1;
    }
    cout << l << endl;
    return 0;
}