#include <algorithm>
#include <iostream>
using namespace std;
string ns[105], dic;
int vis[105], n, m;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> ns[i];
    }
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> dic;
        for (int i = 1; i <= n; i++)
        {
            if (vis[i] == 0 && ns[i].find(dic) != string::npos)
            {
                vis[i] = 1;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << (vis[i] ? "Yes" : "No") << endl;
    }
    return 0;
}