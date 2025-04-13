#include <algorithm>
#include <iostream>
using namespace std;
int a[10005], b[10005], T;
int main()
{
    cin >> T;
    while (T--)
    {
        int n, delta = 0, t = 0;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++)
        {
            cin >> b[i];
            if (a[i] != b[i])
            {
                delta++, t += b[i];
            }
        }
        if (delta % 2 == 1)
        {
            cout << -1 << endl;
            continue;
        }
        // 同侧两个1可以1次操作 异侧两个1需要2次操作
        int ans = t / 2 + (delta - t) / 2 + t % 2 + (delta - t) % 2;
        cout << ans << endl;
    }
    return 0;
}