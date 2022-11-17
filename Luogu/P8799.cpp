#include <iostream>
using namespace std;
#define MX 200005
int ans[MX], vis[MX];
int main()
{
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        vis[x]++;
        if (vis[x] > 1)
        {
            ans[1] = 1;
        }
    }
    for (int i = 1; i <= 200000; i++)
    {
        if (vis[i] == 0)
        {
            continue;
        }
        for (int j = 2; i * j <= 200000; j++)
        {
            if (vis[i * j])
            {
                ans[j] = 1;
            }
        }
    }
    for (int i = 1; i <= q; i++)
    {
        int x;
        cin >> x;
        if (ans[x])
        {
            cout << "YES" << '\n';
        }
        else
        {
            cout << "NO" << '\n';
        }
    }
    return 0;
}