#include <algorithm>
#include <iostream>
using namespace std;
int a[1000005], n, q;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    while (q--)
    {
        int x;
        cin >> x;
        int pos = upper_bound(a + 1, a + 1 + n, x) - a;
        cout << (pos > n ? -1 : a[pos]) << " ";
        pos = lower_bound(a + 1, a + 1 + n, x) - a - 1;
        cout << (pos == 0 ? -1 : a[pos]) << "\n";
    }
    return 0;
}