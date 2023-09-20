#include <algorithm>
#include <iostream>
using namespace std;
int vis[100005], mp[205][205];
int main()
{
    vis[0] = vis[1] = 1;
    for (int i = 2; i * i <= 100000; i++)
    {
        if (vis[i] == 0)
        {
            for (int j = 2; j * i <= 100000; j++)
            {
                vis[i * j] = 1;
            }
        }
    }
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                int x;
                cin >> x;
                mp[i][j] = (vis[x] == 0 ? mp[i - 1][j] + 1 : 0);
                cout << mp[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}