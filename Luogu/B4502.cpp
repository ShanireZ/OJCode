#include <algorithm>
#include <iostream>
using namespace std;
struct Node
{
    int id, mx, mn, tot;
    bool operator<(const Node &oth) const
    {
        if (tot == oth.tot)
        {
            if (mx == oth.mx)
            {
                if (mn == oth.mn)
                {
                    return id < oth.id;
                }
                return mn < oth.mn;
            }
            return mx < oth.mx;
        }
        return tot < oth.tot;
    }
};
Node ns[1005];
int n, k, v;
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        ns[i] = Node{i, 0, 10000, 0};
        for (int j = 1; j <= k; j++)
        {
            cin >> v;
            ns[i].mx = max(ns[i].mx, v);
            ns[i].mn = min(ns[i].mn, v);
            ns[i].tot += v;
        }
    }
    sort(ns + 1, ns + n + 1);
    for (int i = 1; i <= n; i++)
    {
        cout << ns[i].id << " ";
    }
    cout << endl;
    return 0;
}