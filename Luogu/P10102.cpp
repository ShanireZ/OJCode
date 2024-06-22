#include <algorithm>
#include <cstring>
#include <ctime>
#include <iostream>
#include <random>
using namespace std;
int a[3005][3005], b[3005][3005], c[3005][3005], d[3005];
int tmp[3005], res1[3005], res2[3005], n, T, mod = 998244353;
void read(int op)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> (op == 1 ? a[i][j] : (op == 2 ? b[i][j] : c[i][j]));
        }
    }
}
void multi(int x[3005], int y[3005][3005], int op)
{
    memset(tmp, 0, sizeof(tmp));
    for (int j = 1; j <= n; j++)
    {
        for (int k = 1; k <= n; k++)
        {
            tmp[j] = (tmp[j] + 1ll * x[k] * y[k][j] % mod) % mod;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        op == 1 ? res1[i] = tmp[i] : res2[i] = tmp[i];
    }
}
int main()
{
    cin.tie(0)->ios::sync_with_stdio(false);
    cin >> T;
    while (T--)
    {
        mt19937 rnd(time(0));
        cin >> n;
        read(1), read(2), read(3);
        for (int i = 1; i <= n; i++)
        {
            d[i] = rnd() % mod;
        }
        multi(d, c, 2);
        multi(d, a, 1);
        multi(res1, b, 1);
        int ok = 1;
        for (int i = 1; i <= n; i++)
        {
            if (res1[i] != res2[i])
            {
                ok = 0;
                break;
            }
        }
        cout << (ok ? "Yes" : "No") << '\n';
    }
    return 0;
}
// TAG: 随机化 矩阵乘法