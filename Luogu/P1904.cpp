#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int vis[10005];
int main()
{
    int l, h, r;
    while (cin >> l >> h >> r)
    {
        for (int i = l; i < r; i++)
        {
            vis[i] = max(vis[i], h);
        }
    }
    for (int i = 1; i <= 10000; i++)
    {
        if (vis[i] != vis[i - 1])
        {
            cout << i << " " << vis[i] << " ";
        }
    }
    return 0;
}