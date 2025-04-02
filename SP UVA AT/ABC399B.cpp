#include <algorithm>
#include <iostream>
using namespace std;
struct Node
{
    int p, id;
    bool operator<(const Node &oth) const
    {
        return p > oth.p;
    }
};
Node ns[105];
int n, rk[105];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> ns[i].p;
        ns[i].id = i;
    }
    sort(ns + 1, ns + n + 1);
    for (int i = 1; i <= n; i++)
    {
        ns[i].p != ns[i - 1].p ? rk[ns[i].id] = i : rk[ns[i].id] = rk[ns[i - 1].id];
    }
    for (int i = 1; i <= n; i++)
    {
        cout << rk[i] << endl;
    }
    return 0;
}