#include <iostream>
#include <algorithm>
using namespace std;
//tomb為原數列
//a為tomb差分 at為a的樹狀陣列 find(i)為計算a[i]的前綴和
//ia[i]為i*a[i] iat為ia的樹狀陣列 ifind(i)為計算ia[i]的前綴和
//最終數列的每一項 tomb_final[i] = ∑a[i] 範圍1-i = find(i)
//最終數列第p項的前綴和 tot[p]= tomb_final[1] + ... + tomb_final[p]
//                          = ∑a[1] + ... + ∑a[p] 範圍1-i
//                          = ∑(∑a[i]) 前一個1-p 後一個1-i
//                          = (p+1)*∑a[i] - ∑i*a[i] 範圍1-p
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
    long long pre = at[now] * now;       //坑啊 加減的不隨now的變化而變化
    long long aft = (at[now] + x) * now; //坑啊 加減的不隨now的變化而變化
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
        if (t == 1) //lr間加k
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
        else if (t == 3) //主墓碑減k
        {
            cin >> k;
            edit(1, -k);
            edit(2, k);
        }
        else if (t == 4) //求lr間風水和
        {
            cin >> l >> r;
            Node nr = findnow(r);
            Node nl = findnow(l - 1);
            long long ar = (r + 1) * nr.ans - nr.ians;
            long long al = l * nl.ans - nl.ians;
            cout << ar - al << endl;
        }
        else if (t == 5) //求主墓碑的風水值
        {
            cout << findnow(1).ans << endl;
        }
    }
    return 0;
}