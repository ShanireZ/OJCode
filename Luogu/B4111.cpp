#include <algorithm>
#include <iostream>
using namespace std;
int a[105], n, m, ans;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++)
    {
        int b;
        cin >> b;
        for (int j = 1; j <= n; j++)
        {
            ans += (a[j] + b) * max(a[j], b);
        }
    }
    cout << ans << endl;
    return 0;
}