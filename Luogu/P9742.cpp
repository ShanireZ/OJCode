#include <iostream>
using namespace std;
long long c[200005];
main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> c[i];
        }
        for (int i = 1; i <= n; i++)
        {
            cin >> c[i];
        }
        long long ans = 0, pre = -c[1];
        for (int i = 2; i <= n; i++)
        {
            ans = max(ans, pre + c[i]);
            pre = max(pre + abs(c[i]), -c[i]);
        }
        cout << ans << endl;
    }
    return 0;
}