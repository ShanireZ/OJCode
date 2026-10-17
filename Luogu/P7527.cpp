#include <iostream>
using namespace std;
// 這尼瑪不就是P1972HH的項鍊嗎? SP3267 DQUERY - D-query三倍經驗的快樂
// tree樹狀陣列 last每個數字最後一次出現的位置
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
    // 枚舉每個R能組成多少個組合
    // 如果之前R出現過，那麼L必然在上一次出現之後，再看看上一次R之後有幾個其他數
    // 如果之前R沒出現過，之前出現過幾個其他數，就能形成幾個組合
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