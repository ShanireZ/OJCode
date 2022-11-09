#include <iostream>
using namespace std;
long long a[100005];
int main()
{
    int n, k;
    cin >> n >> k;
    long long l = 1, r = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] *= a[i];
        l = max(l, a[i]), r += a[i];
    }
    while (l <= r)
    {
        long long mid = (l + r) / 2, tot = 0, cnt = 1;
        for (int i = 1; i <= n; i++)
        {
            (tot + a[i] > mid) ? cnt++, tot = a[i] : tot += a[i];
        }
        (cnt > k) ? l = mid + 1 : r = mid - 1;
    }
    cout << l << endl;
    return 0;
}