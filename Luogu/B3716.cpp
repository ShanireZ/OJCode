#include <iostream>
using namespace std;
#define MX 100000005
int prim[MX], vis[MX], pos, read();
int main()
{
    for (int i = 2; i <= MX; i++)
    {
        if (vis[i] == 0)
        {
            prim[++pos] = i, vis[i] = i;
        }
        for (int j = 1; j <= pos && i * prim[j] <= MX; j++)
        {
            vis[i * prim[j]] = prim[j];
            if (i % prim[j] == 0)
            {
                break;
            }
        }
    }
    int t = read();
    while (t--)
    {
        int n = read(), ans = 0;
        while (n != 1)
        {
            ans ^= vis[n], n /= vis[n];
        }
        cout << ans << "\n";
    }
    return 0;
}
int read()
{
    int ans = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        ans = ans * 10 + ch - '0';
        ch = getchar();
    }
    return ans;
}