#include <algorithm>
#include <iostream>
using namespace std;
int prim[100005], vis[100005], pos, n, x;
int main()
{
    vis[0] = vis[1] = 1;
    for (int i = 2; i <= 100000; i++)
    {
        if (vis[i] == 0)
        {
            prim[++pos] = i;
        }
        for (int j = 1; j <= pos && i * prim[j] <= 100000; j++)
        {
            vis[i * prim[j]] = 1;
            if (i % prim[j] == 0)
            {
                break;
            }
        }
    }
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        if (vis[x] == 0)
        {
            cout << x << " ";
        }
    }
    return 0;
}