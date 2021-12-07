#include <iostream>
using namespace std;
// 这尼玛不就是P1972HH的项链吗?
// tree树状数组 last每个数字最后一次出现的位置
int tree[200005], last[200005], n;
int lowbit(int x)
{
    return x & -x;
}
void edit(int x, int add)
{
    while (x <= n)
    {
        tree[x] += add;
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
    cin >> n;
    long long ans = 0;
    // 枚举每个R能组成多少个组合
    // 如果之前R出现过，那么L必然在上一次出现之后，再看看上一次R之后有几个其他数
    // 如果之前R没出现过，之前出现过几个其他数，就能形成几个组合
    for (int i = 1; i <= n; i++)
    {
        int now;
        cin >> now;
        ans += query(i - 1);
        if (last[now])
        {
            ans -= query(last[now]);
            edit(last[now], -1);
        }
        edit(i, 1);
        last[now] = i;
    }
    cout << ans << endl;
    return 0;
}