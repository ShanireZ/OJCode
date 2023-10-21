#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
int vis[100005];
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        memset(vis, 0, sizeof(vis));
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            int now = i;
            while (now <= n && vis[now] == 0)
            {
                cout << now << " ";
                vis[now] = 1, now *= 2;
            }
        }
        cout << endl;
    }
    return 0;
}