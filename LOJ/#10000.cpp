#include <iostream>
#include <algorithm>
using namespace std;
struct Node
{
    int x, y;
};
Node ns[1005];
bool cmp(Node a, Node b)
{
    return a.y < b.y;
}
int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> ns[i].x >> ns[i].y;
    }

    sort(ns + 1, ns + 1 + n, cmp);
    int cur = 0, tot = 0;

    for (int i = 1; i <= n; i++)
    {
        if (ns[i].x >= cur)
        {
            tot++;
            cur = ns[i].y;
        }
    }

    cout << tot;
    return 0;
}