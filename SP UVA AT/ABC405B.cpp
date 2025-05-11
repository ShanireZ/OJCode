#include <algorithm>
#include <iostream>
using namespace std;
int n, m, p, cnt, vis[105];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        if (vis[a] == 0)
        {
            vis[a] = 1, cnt++;
        }
        if (cnt < m)
        {
            p = i;
        }
    }
    cout << n - p << endl;
    return 0;
}