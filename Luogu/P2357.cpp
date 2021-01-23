#include <iostream>
#include <algorithm>
using namespace std;
//tomb为原数列
//a为tomb差分 at为a的树状数组 find(i)为计算a[i]的前缀和
//ia[i]为i*a[i] iat为ia的树状数组 ifind(i)为计算ia[i]的前缀和
//最终数列的每一项 tomb_final[i] = ∑a[i] 范围1-i = find(i)
//最终数列第p项的前缀和 tot[p]= tomb_final[1] + ... + tomb_final[p]
//                          = ∑a[1] + ... + ∑a[p] 范围1-i
//                          = ∑(∑a[i]) 前一个1-p 后一个1-i
//                          = (p+1)*∑a[i] - ∑i*a[i] 范围1-p
//                          = (p+1)*find(i) - ifind(i)
struct Node
{
    long long ans, ians;
};
long long at[200005], iat[200005], tomb[200005];
int n, f;
int lowbit(int x)
{
    return x & -x;
}
void edit(int now, int x)
{
    long long pre = at[now] * now;       //坑啊 加减的不随now的变化而变化
    long long aft = (at[now] + x) * now; //坑啊 加减的不随now的变化而变化
    while (now <= n)
    {
        iat[now] = iat[now] - pre + aft;
        at[now] += x;
        now += lowbit(now);
    }
}
Node findnow(int now)
{
    Node tmp;
    tmp.ans = tmp.ians = 0;
    while (now)
    {
        tmp.ans += at[now];
        tmp.ians += iat[now];
        now -= lowbit(now);
    }
    return tmp;
}
int main()
{
    cin >> n >> f;
    for (int i = 1; i <= n; i++)
    {
        cin >> tomb[i];
        edit(i, tomb[i] - tomb[i - 1]);
    }
    for (int i = 1; i <= f; i++)
    {
        int t, l, r, k;
        cin >> t;
        if (t == 1) //lr间加k
        {
            cin >> l >> r >> k;
            edit(l, k);
            edit(r + 1, -k);
        }
        else if (t == 2) //主墓碑加k
        {
            cin >> k;
            edit(1, k);
            edit(2, -k);
        }
        else if (t == 3) //主墓碑减k
        {
            cin >> k;
            edit(1, -k);
            edit(2, k);
        }
        else if (t == 4) //求lr间风水和
        {
            cin >> l >> r;
            Node nr = findnow(r);
            Node nl = findnow(l - 1);
            long long ar = (r + 1) * nr.ans - nr.ians;
            long long al = l * nl.ans - nl.ians;
            cout << ar - al << endl;
        }
        else if (t == 5) //求主墓碑的风水值
        {
            cout << findnow(1).ans << endl;
        }
    }
    return 0;
}