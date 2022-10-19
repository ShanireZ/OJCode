#include <iostream>
using namespace std;
int tree[100005], n;
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
    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        ans += query(n) - query(x);
        edit(x);
    }
    cout << ans << endl;
    return 0;
}