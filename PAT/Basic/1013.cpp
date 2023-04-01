#include <algorithm>
#include <iostream>
using namespace std;
int prim[200005], vis[200005], pos;
int main()
{
    for (int i = 2; i <= 200000; i++)
    {
        if (vis[i] == 0)
        {
            prim[++pos] = i;
        }
        for (int j = 1; j <= pos && prim[j] * i <= 200000; j++)
        {
            vis[prim[j] * i] = 1;
            if (i % prim[j] == 0)
            {
                break;
            }
        }
    }
    int m, n, cnt = 0;
    cin >> m >> n;
    for (int i = m; i <= n; i++)
    {
        cout << prim[i];
        cnt = (cnt + 1) % 10;
        if (i != n)
        {
            cout << (cnt == 0 ? "\n" : " ");
        }
    }
    return 0;
}
