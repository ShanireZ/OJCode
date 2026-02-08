#include <algorithm>
#include <iostream>
using namespace std;
int n, m, ans;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int c, ok = 2e9;
        cin >> c;
        for (int j = 1; j <= c; j++)
        {
            int l, r;
            cin >> l >> r;
            if (l > ans)
            {
                ok = min(ok, r);
            }
        }
        if (ok == 2e9)
        {
            cout << -1 << endl;
            return 0;
        }
        ans = ok;
    }
    cout << ans << endl;
    return 0;
}