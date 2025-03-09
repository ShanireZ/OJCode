#include <algorithm>
#include <iostream>
using namespace std;
int n, m, t, a[100005], p[100005], vis[100005];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        p[a[i]] = i;
    }
    while (m--)
    {
        cin >> t;
        vis[t] = 1;
    }
    for (int i = 1; i < n; i++)
    {
        int pi = p[i];
        p[i] = i, p[a[i]] = pi;
        swap(a[i], a[pi]);
        if (vis[i])
        {
            for (int j = 1; j <= n; j++)
            {
                cout << a[j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}