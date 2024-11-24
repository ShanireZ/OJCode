#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct Node
{
    int l, r;
    bool operator<(const Node &oth) const
    {
        return l < oth.l;
    }
};
vector<Node> ns;
int a[1000005];
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        ns.clear();
        for (int i = 1; i <= n; i++)
        {
            if (a[i] != i)
            {
                ns.emplace_back(Node{min(a[i], i), max(a[i], i)});
            }
        }
        sort(ns.begin(), ns.end());
        int ans = 0, l = 0, r = -1;
        for (Node nd : ns)
        {
            if (nd.l > r)
            {
                ans += r - l + 1;
                l = nd.l, r = nd.r;
            }
            r = max(r, nd.r);
        }
        ans += r - l + 1;
        cout << ans << endl;
    }
    return 0;
}