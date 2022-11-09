#include <iostream>
#include <algorithm>
using namespace std;
int n, q, p, tree[30005], nums[30005], last[1000005];
struct Quest
{
    int l, r, ans, id;
};
Quest qst[200005];
bool cmpr(Quest a, Quest b)
{
    return a.r < b.r;
}
bool cmpid(Quest a, Quest b)
{
    return a.id < b.id;
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
    int ans = 0;
    while (x)
    {
        ans += tree[x];
        x -= lowbit(x);
    }
    return ans;
}
int count(int l, int r)
{
    while (p < r) // p已插入树状数组中的数的位置
    {
        int now = nums[++p];
        if (last[now])
        {
            edit(last[now], -1);
        }
        last[now] = p;
        edit(p, 1);
    }
    return query(r) - query(l - 1);
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> nums[i];
    }
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        cin >> qst[i].l >> qst[i].r;
        qst[i].id = i;
    }
    sort(qst + 1, qst + 1 + q, cmpr);
    for (int i = 1; i <= q; i++)
    {
        qst[i].ans = count(qst[i].l, qst[i].r);
    }
    sort(qst + 1, qst + 1 + q, cmpid);
    for (int i = 1; i <= q; i++)
    {
        cout << qst[i].ans << endl;
    }
    return 0;
}