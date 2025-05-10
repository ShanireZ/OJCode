#include <algorithm>
#include <iostream>
using namespace std;
struct Node
{
    int l, r;
};
Node ns[500005];
void del(int x, int l, int r)
{
    if (ns[x].l == -1)
    {
        return;
    }
    ns[l].r = r, ns[r].l = l;
    ns[x].l = ns[x].r = -1;
}
void add(int x, int l, int r)
{
    ns[l].r = ns[r].l = x;
    ns[x].l = l, ns[x].r = r;
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i <= n + 1; i++)
    {
        ns[i] = Node{i - 1, i + 1};
    }
    while (m--)
    {
        int op, x, y;
        cin >> op >> x;
        del(x, ns[x].l, ns[x].r);
        if (op <= 2)
        {
            cin >> y;
            if (x == y)
            {
                continue;
            }
            op == 1 ? add(x, ns[y].l, y) : add(x, y, ns[y].r);
        }
    }
    for (int i = ns[0].r; i != n + 1; i = ns[i].r)
    {
        cout << i << " ";
    }
    if (ns[0].r == n + 1)
    {
        cout << "Empty!" << endl;
    }
    return 0;
}