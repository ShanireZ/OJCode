#include <algorithm>
#include <iostream>
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
    int trig = 0;
    for (int i = 1; i <= 10000; i++)
    {
        if (vis[i] != vis[i - 1])
        {
            if (trig)
            {
                cout << " ";
            }
            cout << i << " " << vis[i];
            trig = 1;
        }
    }
    cout << endl;
    return 0;
}