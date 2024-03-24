#include <algorithm>
#include <iostream>
using namespace std;
long long mod = 1000000007;
long long c[1005][1005], a[1005];
int main()
{
    for (int i = 0; i <= 1001; i++)
    {
        c[i][0] = 1;
        for (int j = 1; j <= i; j++)
        {
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
        }
    }
    int T;
    cin >> T;
    while (T--)
    {
        int n, m, tot = 0;
        cin >> n >> m;
        for (int i = 1; i <= m; i++)
        {
            cin >> a[i];
            tot += a[i];
        }
        long long res = 1;
        for (int i = 1; i <= m; i++)
        {
            res = res * c[tot][a[i]] % mod;
            tot -= a[i];
        }
        cout << res << endl;
        continue;
    }
    return 0;
}