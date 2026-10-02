#include <algorithm>
#include <iostream>
using namespace std;
int T, n, k;
string r;
int main()
{
    cin >> T;
    while (T--)
    {
        cin >> n >> k >> r;
        int mx = 0, mn = 0, delta = 1e9, c1 = 0, c2 = 0;
        r = "x" + r;
        for (int i = 1; i <= k; i++)
        {
            int c[2] = {1, 0}, now = 0;
            for (int j = i + k; j <= n; j += k)
            {
                now ^= (r[j - k] ^ r[j - k + 1]);
                c[now]++;
            }
            mx += max(c[0], c[1]), mn += min(c[0], c[1]);
            delta = min(delta, abs(c[0] - c[1]));
            c[0] > c[1] ? c1++ : c2++;
        }
        if (c1 % 2 != r[1] - '0')
        {
            mx -= delta;
        }
        if (c2 % 2 != r[1] - '0')
        {
            mn += delta;
        }
        cout << mn << " " << mx << endl;
    }
    return 0;
}