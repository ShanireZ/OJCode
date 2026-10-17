#include <algorithm>
#include <cmath>
#include <iostream>
#include <stack>
using namespace std;
#define MX 100005
int a[MX], dp[MX], pre[MX], st[MX][20], ys[305], posy, maxa, read();
stack<int> stk;
int main()
{
    int n = read(), k = read();
    a[0] = 1e9, stk.push(0);
    for (int i = 1; i <= n; i++)
    {
        a[i] = read();
        while (a[stk.top()] <= a[i]) // 找到每個數前方第一個大於它的數
        {
            stk.pop();
        }
        pre[i] = stk.top();
        stk.push(i), maxa = max(maxa, a[i]);
    }
    for (int i = 1; i * i <= maxa; i++) // 答案必然為最大值的因數
    {
        if (maxa % i == 0)
        {
            ys[++posy] = i, ys[++posy] = maxa / i;
        }
    }
    posy = (ys[posy] == ys[posy - 1] ? posy - 1 : posy); // 如果最大值是完全平方數,則只有一個因數
    sort(ys + 1, ys + posy + 1);                         // 從最大因數開始測試
    for (int i = posy; i >= 1; i--)                      // 如果當前因數可以劃分的區間大於等於k則滿足要求
    {
        for (int j = 1; j <= n; j++) // 枚舉結尾
        {
            dp[j] = dp[pre[j]];    // 如果當前數沒有這個因數,則從前方直接繼承
            if (a[j] % ys[i] == 0) // 如果當前數有這個因數,則等於前方最佳答案+1
            {
                int x = log2(j - 1 - pre[j] + 1);
                int p = j - 1 - (1 << x) + 1;
                int now = max(st[pre[j]][x], st[p][x]);          // now為 pre[j]~j-1 中最大的dp值
                dp[j] = (pre[j] != 0 && now == 0 ? 0 : now + 1); // 如果前方沒有答案,則當前答案也為0
            }
            st[j][0] = dp[j];      // 維護動態ST表中以j結尾的部分
            int lim = log2(j + 1); // 注意是從0開始所以是j+1個
            for (int k = 1; k <= lim; k++)
            {
                int p1 = j - (1 << k) + 1, p2 = j - (1 << (k - 1)) + 1;
                st[p1][k] = max(st[p1][k - 1], st[p2][k - 1]);
            }
        }
        if (dp[n] >= k)
        {
            printf("%d\n", ys[i]);
            break;
        }
    }
    return 0;
}
int read()
{
    int ans = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        ans = ans * 10 + ch - '0';
        ch = getchar();
    }
    return ans;
}
// TAG: RMQ ST表 因數 單調棧 貪心