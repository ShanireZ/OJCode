#include <algorithm>
#include <iostream>
using namespace std;
int a[100005], b[100005], n, m;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> b[i];
    }
    sort(b + 1, b + m + 1);
    for (int i = 1; i <= n; i++)
    {
        int res = *lower_bound(b + 1, b + m + 1, a[i]);
        if (res == a[i])
        {
            cout << res << " ";
        }
    }
    return 0;
}