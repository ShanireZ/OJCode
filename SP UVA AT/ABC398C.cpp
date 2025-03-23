#include <algorithm>
#include <iostream>
using namespace std;
struct Node
{
    int v, id;
    bool operator<(const Node &oth) const
    {
        return v < oth.v;
    }
};
Node ns[300005];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> ns[i].v;
        ns[i].id = i;
    }
    sort(ns + 1, ns + n + 1);
    for (int i = n; i >= 1; i--)
    {
        if (ns[i].v != ns[i - 1].v && ns[i].v != ns[i + 1].v)
        {
            cout << ns[i].id << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}