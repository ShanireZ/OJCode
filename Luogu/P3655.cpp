#include <iostream>
using namespace std;
long long tree[200005], b, s, t;
int n, q;
int lowbit(int x)
{
    return x & -x;
}
void edit(int id, long long add)
{
    while (id <= n)
    {
        tree[id] += add;
        id += lowbit(id);
    }
}
long long query(int id)
{
    long long ans = 0;
    while (id)
    {
        ans += tree[id];
        id -= lowbit(id);
    }
    return ans;
}
void count(long long pre, long long cur)
{
    if (cur > pre)
    {
        b -= s * (cur - pre);
    }
    else
    {
        b += t * (pre - cur);
    }
}
void rcount(long long pre, long long cur)
{
    if (cur > pre)
    {
        b += s * (cur - pre);
    }
    else
    {
        b -= t * (pre - cur);
    }
}
int main()
{
    cin >> n >> q >> s >> t >> b;
    long long cur = 0, pre = 0;
    for (int i = 1; i <= n; i++)
    {
        pre = cur;
        cin >> cur;
        edit(i, cur - pre);
        count(pre, cur);
    }
    for (int i = 1; i <= q; i++)
    {
        int x, y;
        long long z;
        cin >> x >> y >> z;
        rcount(query(x - 1), query(x));
        rcount(query(y), query(y + 1));
        edit(x, z);
        edit(y + 1, -z);
        count(query(x - 1), query(x));
        count(query(y), query(y + 1));
        cout << b << endl;
    }
    return 0;
}