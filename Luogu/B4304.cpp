#include <algorithm>
#include <iostream>
using namespace std;
struct Node
{
    int x, y;
};
Node ns[100005];
bool cmp(Node a, Node b)
{
    return (a.x - a.y) < (b.x - b.y);
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> ns[i].x >> ns[i].y;
    }
    sort(ns + 1, ns + n + 1, cmp);
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        res = max(res + ns[i].y, ns[i].x);
    }
    cout << res << endl;
    return 0;
}