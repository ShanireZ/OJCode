#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
int T, n, a, c[100005];
int main()
{
    cin >> T;
    while (T--)
    {
        cin >> n;
        memset(c, 0, sizeof(c));
        int mx = 0, res = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> a;
            c[a]++, mx = max(mx, a);
        }
        for (int i = 1; i < mx; i++)
        {
            res += (c[i] >= 2) * 2;
        }
        cout << res + 1 << endl;
    }
    return 0;
}