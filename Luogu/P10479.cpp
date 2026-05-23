#include <algorithm>
#include <iostream>
using namespace std;
int n, m, q, cnt[200005];
long long base = 233, mod = 1e9 + 7, h1[200005], h2[200005], pw[200005];
int main()
{
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++)
    {
        char c;
        cin >> c;
        h1[i] = (h1[i - 1] * base + c) % mod;
    }
    pw[0] = 1;
    for (int i = 1; i <= m; i++)
    {
        char c;
        cin >> c;
        h2[i] = (h2[i - 1] * base + c) % mod;
        pw[i] = (pw[i - 1] * base) % mod;
    }
    for (int st = 1; st <= n; st++)
    {
        int l = 0, r = min(m, n - st + 1);
        while (l <= r)
        {
            int mid = (l + r) / 2, check = 1;
            if (h2[mid] != (h1[st + mid - 1] - h1[st - 1] * pw[mid] % mod + mod) % mod)
            {
                check = 0;
            }
            check ? l = mid + 1 : r = mid - 1;
        }
        cnt[r]++;
    }
    while (q--)
    {
        int x;
        cin >> x;
        cout << cnt[x] << endl;
    }
    return 0;
}