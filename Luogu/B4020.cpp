#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int n, m, a, b, ans = 0;
    cin >> n >> m >> a >> b;
    for (int i = 1; i <= m; i++)
    {
        int t, p, ok = 0;
        cin >> t;
        for (int j = 1; j <= t; j++)
        {
            cin >> p;
            if (p == a && ok == 0)
            {
                ok = 1;
            }
            else if (p == b && ok == 1)
            {
                ok = 2;
            }
        }
        ans += (ok == 2);
    }
    cout << ans << endl;
    return 0;
}