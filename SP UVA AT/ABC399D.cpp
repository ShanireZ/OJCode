#include <algorithm>
#include <iostream>
#include <map>
using namespace std;
struct Node
{
    int v1, v2;
    bool operator<(const Node &oth) const
    {
        if (v1 == oth.v1)
        {
            return v2 < oth.v2;
        }
        return v1 < oth.v1;
    }
};
map<Node, int> mp;
int a[400005], vis[400005], n, t, res;
int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n;
        res = a[0] = a[n + n + 1] = 0, mp.clear();
        fill(vis + 1, vis + 1 + n, 0);
        for (int i = 1; i <= n + n; i++)
        {
            cin >> a[i];
        }
        for (int i = 2; i <= n + n; i++)
        {
            if (a[i] == a[i - 1])
            {
                vis[a[i]] = 1;
            }
        }
        for (int i = 2; i <= n + n; i++)
        {
            if (vis[a[i - 1]] == 0 && vis[a[i]] == 0)
            {
                int x = min(a[i], a[i - 1]), y = max(a[i], a[i - 1]);
                if (mp[Node{x, y}] == 0)
                {
                    mp[Node{x, y}] = i;
                }
                else if (mp[Node{x, y}] != i - 1)
                {
                    res++;
                }
            }
        }
        cout << res << endl;
    }
    return 0;
}