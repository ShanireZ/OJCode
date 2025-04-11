#include <algorithm>
#include <iostream>
using namespace std;
struct Node
{
    long long a, b, delta;
    bool operator<(const Node &oth) const
    {
        return delta < oth.delta;
    }
};
Node ns[200005];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n + n; i++)
    {
        cin >> ns[i].a;
    }
    for (int i = 1; i <= n + n; i++)
    {
        cin >> ns[i].b;
        ns[i].delta = ns[i].a - ns[i].b;
    }
    sort(ns + 1, ns + n + n + 1);
    long long res = 0;
    for (int i = 1; i <= n + n; i++)
    {
        res += (i <= n ? ns[i].b : ns[i].a);
    }
    cout << res << endl;
    return 0;
}