#include <algorithm>
#include <iostream>
using namespace std;
struct Node
{
    int l, r;
};
Node ns[100005];
bool cmp(Node a, Node b)
{
    return a.r < b.r;
}
int n, m, ans;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int c, ok = 0;
        cin >> c;
        for (int j = 1; j <= c; j++)
        {
            cin >> ns[j].l >> ns[j].r;
        }
        sort(ns + 1, ns + c + 1, cmp);
        for (int j = 1; j <= c; j++)
        {
            if (ns[j].l > ans)
            {
                ans = ns[j].r, ok = 1;
                break;
            }
        }
        if (ok == 0)
        {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << ans << endl;
    return 0;
}