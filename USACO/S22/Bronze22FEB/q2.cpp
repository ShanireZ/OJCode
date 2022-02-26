#include <iostream>
using namespace std;
int a[100005], b[100005], n, tree[100005];
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
    int ans = 0;
    while (x)
    {
        ans += tree[x];
        x -= lowbit(x);
    }
    return ans;
}
int main()
{
    int n, ans = 0, minn = 1e9;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        a[x] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        b[i] = a[x];
    }
    for (int i = n; i >= 1; i--)
    {
        if (b[i] > minn)
        {
            ans++;
        }
        minn = min(minn, b[i]);
    }
    cout << ans << endl;
    return 0;
}