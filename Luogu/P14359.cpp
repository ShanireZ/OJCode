#include <algorithm>
#include <iostream>
using namespace std;
struct Node
{
    int l, r;
    bool operator<(const Node &oth) const
    {
        return r < oth.r;
    }
};
Node ns[500005];
int n, k, pos, qz, a, lst[1100000];
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        qz ^= a;
        if ((qz ^ k) == 0 || lst[qz ^ k])
        {
            ns[++pos] = Node{lst[qz ^ k] + 1, i};
        }
        lst[qz] = i;
    }
    sort(ns + 1, ns + pos + 1);
    int ans = (pos != 0), ed = ns[1].r;
    for (int i = 2; i <= pos; i++)
    {
        if (ns[i].l > ed)
        {
            ed = ns[i].r, ans++;
        }
    }
    cout << ans << endl;
    return 0;
}