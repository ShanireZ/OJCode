#include <cstring>
#include <iostream>
using namespace std;
int ans[70000], times[70000], last[70000], f[25005];
int main()
{
    int s, t;
    cin >> s >> t;
    while (t--)
    {
        memset(times, 0, sizeof(times)), memset(last, 0, sizeof(last));
        memset(ans, 0, sizeof(ans)), memset(f, 0, sizeof(f));
        int n, x, y;
        cin >> n >> x >> y;
        for (int i = 1; i <= n; i++)
        {
            int x;
            cin >> x;
            times[x]++, last[x] = i;
        }
        for (int i = 65535; i >= 0; i--)
        {
            if (times[i] % 2 == 1)
            {
                ans[i] = 1;
            }
            else if (times[i] && y)
            {
                ans[i] = f[last[i]] = 1, y--;
            }
        }
        for (int i = n; y && i > 1; i--) // 必须从后向前，不然有可能让1变0
        {
            if (f[i] == 0)
            {
                f[i] = 1, y--;
            }
        }
        int ok = 0;
        for (int i = 65535; i >= 0; i--)
        {
            if (ok || ans[i])
            {
                cout << ans[i];
                ok = 1;
            }
        }
        if (ok == 0)
        {
            cout << 0;
        }
        cout << '\n';
        for (int i = 2; i <= n; i++)
        {
            (f[i]) ? cout << '|' : cout << '^';
        }
        cout << '\n';
    }
    return 0;
}