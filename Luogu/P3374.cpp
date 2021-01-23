#include <iostream>
using namespace std;
int tree[500005], n, m;
int lowbit(int x)
{
    return x & -x;
}
void edit(int id, int add)
{
    while (id <= n)
    {
        tree[id] += add;
        id += lowbit(id);
    }
}
int query(int id)
{
    int ans = 0;
    while (id)
    {
        ans += tree[id];
        id -= lowbit(id);
    }
    return ans;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        edit(i, x);
    }
    for (int i = 1; i <= m; i++)
    {
        int op, x, y;
        cin >> op >> x >> y;
        if (op == 1)
        {
            edit(x, y);
        }
        else
        {
            cout << query(y) - query(x - 1) << endl;
        }
    }
    return 0;
}