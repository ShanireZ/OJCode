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
        ns[i].id = i;   //出現順序
    }
    sort(ns + 1, ns + 1 + n, cmp);
    int ans = 1;
    for (int i = 1; i <= n; i++)
    {
        edit(ns[i].id, 1); //樹狀陣列標記 出現順序
        ans = max(ans, i - query(i));
        //如果完成冒泡排序，那麼當前位置上的數應該是第i小的數
        //因為已經從小到大排序，所以之前處理的數肯定都是小於等於當前數的數字
        //query(i)可以查到比當前數小的數，有幾個編號小於等於當前數的編號，也就是說有幾個在當前數前面出現
        //當前數是第i個，所以現在一共i個數；前面有query(i)個小於等於它的，那麼大於它的就有i-query(i)個
    }
    cout << ans;
    return 0;
}