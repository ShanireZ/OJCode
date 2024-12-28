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
    int l = 0, r = 1e9;
    while (l <= r)
    {
        int mid = (l + r) / 2, day = 1, sum = 0, mx = 0;
        for (int i = 1; i <= n; i++)
        {
            mx = max(mx, a[i]);
            if (sum + a[i] - mx <= mid)
            {
                sum += a[i];
            }
            else
            {
                day++, sum = mx = a[i];
            }
        }
        day <= m ? r = mid - 1 : l = mid + 1;
    }
    cout << l << endl;
    return 0;
}