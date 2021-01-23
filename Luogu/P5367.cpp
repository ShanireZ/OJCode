#include <iostream>
#include <algorithm>
using namespace std;
int tree[1000005], n;
long long fact[1000005], mod = 998244353, ans;
//! 康托展开公式 (i = 1~n)∑ ((a_i - 1) * (n - i)!)
//! i表示从左到右第几位 a_i表示当前位的数字是剩余数字中第几大
//! 1 ~ (i - 1) 已经排好的前提下 第i位比当前数字还小的有(a_i - 1)种
//! 右侧还有(n - i)个数字 可形成(n - i)!种排列
//! 那么当前位就会有(a_i - 1) * (n - i)!种更小的可能
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
    cin >> n;
    fact[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        fact[i] = fact[i - 1] * i % mod;
        edit(i, 1);
    }
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        ans = (ans + (query(x) - 1) * fact[n - i] % mod) % mod;
        edit(x, -1);
    }
    cout << (ans + 1) % mod;
    return 0;
}