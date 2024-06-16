#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
set<int> s[500005];
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            s[i].clear();
        }
        for (int i = 1; i <= m; i++)
        {
            int a, b;
            cin >> a >> b;
            s[a].insert(b);
        }
        for (int i = 1; i <= n; i++)
        {
            for (int x : s[i])
            {
                cout << x << " ";
            }
            cout << endl;
        }
    }
    return 0;
}