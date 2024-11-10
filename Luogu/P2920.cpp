#include <algorithm>
#include <iostream>
using namespace std;
struct Node
{
    int t, s;
};
Node ns[1005];
bool cmp(Node a, Node b)
{
    return a.s < b.s;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> ns[i].t >> ns[i].s;
    }
    sort(ns + 1, ns + n + 1, cmp);
    int l = 0, r = 1000000;
    while (l <= r)
    {
        int mid = (l + r) / 2, ok = 1;
        for (int i = 1, now = mid; i <= n; i++)
        {
            if (now + ns[i].t > ns[i].s)
            {
                ok = 0;
                break;
            }
            now += ns[i].t;
        }
        ok ? l = mid + 1 : r = mid - 1;
    }
    cout << r << endl;
    return 0;
}