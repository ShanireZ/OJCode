#include <algorithm>
#include <iostream>
using namespace std;
long long n, a[100005], qz[100005], ans[100005];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
    {
        qz[i] = qz[i - 1] + a[i];
    }
    for (int i = 3; i <= n; i++)
    {
        long long delta = qz[i - 1] - a[i];
        if (delta > 0)
        {
            int l = 1, r = i - 1;
            while (l <= r)
            {
                int mid = (l + r) / 2;
                qz[mid] < delta ? l = mid + 1 : r = mid - 1;
            }
            ans[i - r]++, ans[i + 1]--;
        }
    }
    for (int i = 3; i <= n; i++)
    {
        ans[i] += ans[i - 1];
        if (ans[i])
        {
            cout << i << " ";
        }
    }
    return 0;
}