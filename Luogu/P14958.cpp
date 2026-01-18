#include <algorithm>
#include <iostream>
using namespace std;
struct Node
{
    int v, id;
};
Node ns[100005];
int n, ans[100005];
bool cmp(Node a, Node b)
{
    return a.v < b.v;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> ns[i].v;
        ns[i].id = i;
    }
    sort(ns + 1, ns + n + 1, cmp);
    for (int i = 1; i <= n; i++)
    {
        ans[ns[i].id] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}