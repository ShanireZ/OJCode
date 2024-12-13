#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
int prim[1000005], vis[1000005], pos, res;
int main()
{
    for (int i = 2; i <= 1000000; i++)
    {
        if (vis[i] == 0)
        {
            prim[++pos] = i;
        }
        for (int j = 1; j <= pos && i * prim[j] <= 1000000; j++)
        {
            vis[i * prim[j]] = 1;
            if (i % prim[j] == 0)
            {
                break;
            }
        }
    }
    long long n;
    cin >> n;
    for (int i = 1; i <= pos; i++)
    {
        int cnt = 0;
        while (n % prim[i] == 0)
        {
            cnt++, n /= prim[i];
        }
        res += (sqrt(8 * cnt + 1) - 1) / 2;
    }
    cout << res + (n > 1) << endl;
    return 0;
}