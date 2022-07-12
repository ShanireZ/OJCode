#include <algorithm>
#include <iostream>
using namespace std;
struct Node
{
    int t, v;
    bool operator<(const Node other) const
    {
        return v < other.v;
    }
};
Node ns[200005];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n + m; i++)
    {
        (i <= n) ? ns[i].t = 1 : ns[i].t = 2;
        cin >> ns[i].v;
    }
    sort(ns + 1, ns + 1 + n + m);
    int cnt = 0;
    for (int i = 1; i <= n + m; i++)
    {
        if (ns[i].t == 2)
        {
            cnt++;
        }
        else if (cnt > 0)
        {
            cnt--;
        }
    }
    cout << m - cnt << endl;
    return 0;
}