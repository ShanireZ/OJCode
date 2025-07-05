#include <algorithm>
#include <iostream>
using namespace std;
struct Node
{
    int h, w, id;
};
Node ns[3005];
int n, ans;
bool cmp(Node a, Node b)
{
    if (a.h == b.h && a.w == b.w)
    {
        return a.id < b.id;
    }
    return a.h == b.h ? a.w > b.w : a.h > b.h;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> ns[i].h >> ns[i].w;
        ns[i].id = i;
    }
    sort(ns + 1, ns + n + 1, cmp);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            ans += (ns[i].id < ns[j].id);
        }
    }
    cout << ans << endl;
    return 0;
}