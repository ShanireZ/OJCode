#include <algorithm>
#include <iostream>
using namespace std;
int n, m, q, a[1000005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> q;
        int p = lower_bound(a + 1, a + 1 + n, q) - a;
        cout << (a[p] == q ? p : -1) << "\n";
    }
    return 0;
}