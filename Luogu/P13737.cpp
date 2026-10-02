#include <algorithm>
#include <iostream>
using namespace std;
struct Node
{
    int id, v;
};
Node cake[200005], tea[200005], all[400005];
int n, m, pos;
bool cmpid(Node a, Node b)
{
    if (a.id == b.id)
    {
        return a.v > b.v;
    }
    return a.id < b.id;
}
bool cmpv(Node a, Node b)
{
    return a.v > b.v;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> cake[i].id;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> cake[i].v;
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> tea[i].id;
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> tea[i].v;
    }
    sort(cake + 1, cake + 1 + n, cmpid);
    sort(tea + 1, tea + 1 + m, cmpid);
    int i = 1, j = 1;
    while (i <= n && j <= m)
    {
        if (cake[i].id < tea[j].id)
        {
            all[++pos] = cake[i];
            i++;
        }
        else if (cake[i].id > tea[j].id)
        {
            j++;
        }
        else
        {
            all[++pos] = cake[i];
            all[pos].v += tea[j].v;
            i++, j++;
        }
    }
    while (i <= n)
    {
        all[++pos] = cake[i];
        i++;
    }
    sort(all + 1, all + 1 + pos, cmpv);
    long long ans = 0;
    for (int i = 1; i <= m; i++)
    {
        ans += all[i].v;
    }
    cout << ans << endl;
    return 0;
}