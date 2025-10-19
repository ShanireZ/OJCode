#include <algorithm>
#include <iostream>
using namespace std;
int n, m, a[1000005];
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
        int q;
        cin >> q;
        int p = upper_bound(a + 1, a + 1 + n, q) - a - 1;
        cout << (a[p] == q ? p : -1) << '\n';
    }
    return 0;
}