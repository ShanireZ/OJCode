#include <iostream>
using namespace std;
int n, m, tree[10000005];
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
    for (int i = 1; i <= m; i++)
    {
        int op, a, b;
        cin >> op;
        if (op == 0)
        {
            cin >> a >> b;
            edit(a, 1);
            edit(b + 1, -1);
        }
        else
        {
            cin >> a;
            cout << query(a) << endl;
        }
    }
    return 0;
}