#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
string s;
int ct[3005], rec[3005], rpos, pos;
void opt(int c, int num)
{
    for (int i = 1; i <= c; i++)
    {
        cout << num;
    }
}
int main()
{
    cin >> s;
    int now = 0, cnt = 0;
    for (char c : s)
    {
        if (c == now + '0')
        {
            cnt++;
            continue;
        }
        ct[++pos] = cnt;
        cnt = 1, now = !now;
    }
    ct[++pos] = cnt; // 奇数位:连续0的个数 偶数位:连续1的个数
    int ans = 0;     // 翻转的终点必然是最长的连续0末尾 起点必然是第一个1
    for (int i = (pos % 2 == 0 ? pos - 1 : pos); i > 1; i -= 2)
    {
        if (ct[i] >= ans)
        {
            if (ct[i] > ans)
            {
                ans = ct[i], rpos = 0;
            }
            rec[++rpos] = i;
        }
    }
    ans = rec[1];
    for (int i = 2; i <= rpos; i++)
    {
        for (int ex = 1; rec[i] - ex >= 1; ex++) // ex为奇数时判断的是连续的1的个数,为偶数时判断的是连续的0的个数
        {
            if (ct[rec[i] - ex] == ct[ans - ex])
            {
                continue;
            }
            if ((ex % 2 == 1 && ct[rec[i] - ex] < ct[ans - ex]) ||
                (ex % 2 == 0 && ct[rec[i] - ex] > ct[ans - ex]))
            {
                ans = rec[i]; // 1越少越好 0越多越好
            }
            break;
        }
    }
    opt(ct[1], 0);
    for (int x = ans; x >= 2; x -= 2)
    {
        opt(ct[x], 0), opt(ct[x - 1], 1);
    }
    for (int x = ans + 1; x <= pos; x += 2)
    {
        opt(ct[x], 1), opt(ct[x + 1], 0);
    }
    return 0;
}