#include <iostream>
using namespace std;
int ans, n, p[100005], tree[100005];
int lowbit(int x)
{
    return x & -x;
}
void edit(int x)
{
    while (x <= n)
    {
        tree[x]++;
        x += lowbit(x);
    }
}
int query(int x)
{
    int cnt = 0;
    while (x)
    {
        cnt += tree[x];
        x -= lowbit(x);
    }
    return cnt;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
    }
    for (int i = n - 1; i >= 1; i--)
    {
        if (p[i] > p[i + 1])
        {
            ans = i;
            break;
        }
    }
    cout << ans << endl;
    for (int i = ans + 1; i <= n; i++)
    {
        edit(p[i]);
    }
    for (int i = 1; i <= ans; i++)
    {
        cout << query(p[i]) + (ans - i) << " ";
        edit(p[i]);
    }
    return 0;
}