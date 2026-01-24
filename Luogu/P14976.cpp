#include <algorithm>
#include <iostream>
using namespace std;
int s[505][505], a[505][505], n, k, q, ans;
int main()
{
    cin >> n >> k >> q;
    while (q--)
    {
        int r, c, v;
        cin >> r >> c >> v;
        for (int i = r; i >= max(r - k + 1, 1); i--)
        {
            for (int j = c; j >= max(c - k + 1, 1); j--)
            {
                s[i][j] += v - a[r][c];
                ans = max(ans, s[i][j]);
            }
        }
        cout << ans << endl;
        a[r][c] = v;
    }
    return 0;
}