#include <iostream>
using namespace std;
int a[500005];
int b[500005]; //增量差分
int n, m;
int lowbit(int x)
{
    return x & -x;
}
void edit(int x, int k)
{
    while (x <= n)
    {
        b[x] += k;
        x += lowbit(x);
    }
}
int count(int x)
{
    int tot = 0;
    while (x)
    {
        tot += b[x];
        x -= lowbit(x);
    }
    return tot;
}
int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++)
    {
        int op, x, y, k;
        cin >> op >> x;
        if (op == 1)
        {
            cin >> y >> k;
            edit(x, k);
            edit(y + 1, -k);
        }
        else
        {
            cout << count(x) + a[x] << endl;
        }
    }
    return 0;
}