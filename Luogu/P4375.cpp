#include <iostream>
#include <algorithm>
using namespace std;
int n, tree[100005];
struct Node
{
    int x, id;
};
Node ns[100005];
bool cmp(Node a, Node b)
{
    return a.x < b.x;
}
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
    int tot = 0;
    while (x)
    {
        tot += tree[x];
        x -= lowbit(x);
    }
    return tot;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> ns[i].x; //值
        ns[i].id = i;   //出现顺序
    }
    sort(ns + 1, ns + 1 + n, cmp);
    int ans = 1;
    for (int i = 1; i <= n; i++)
    {
        edit(ns[i].id, 1); //树状数组标记 出现顺序
        ans = max(ans, i - query(i));
        //如果完成冒泡排序，那么当前位置上的数应该是第i小的数
        //因为已经从小到大排序，所以之前处理的数肯定都是小于等于当前数的数字
        //query(i)可以查到比当前数小的数，有几个编号小于等于当前数的编号，也就是说有几个在当前数前面出现
        //当前数是第i个，所以现在一共i个数；前面有query(i)个小于等于它的，那么大于它的就有i-query(i)个
    }
    cout << ans;
    return 0;
}