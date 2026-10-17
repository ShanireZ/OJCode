#include <algorithm>
#include <iostream>
using namespace std;
long long l, r, ans;
long long f(long long ed) // 從0開始每4個數一區,區域內有趣數要麼是i和i+3,要麼是i+1和i+2
{
    long long res = 0, lmt = ed / 4 * 4;
    for (int i = 0; i + 3 < lmt; i += 4) // 處理前方區域,可用等差數列直接計算
    {
        res += i + (i + 3);
    }
    int x = lmt, cnt = 0; // 處理最後一個區域
    while (x)
    {
        cnt += x % 2;
        x /= 2;
    }
    for (int i = lmt; i <= ed; i++) // 如果i內1的個數是奇數,則i和i+3是有趣數,否則i+1和i+2是有趣數
    {
        if (cnt % 2 == 1 && (i == lmt || i == lmt + 3))
        {
            res += i;
        }
        else if (cnt % 2 == 0 && (i == lmt + 1 || i == lmt + 2))
        {
            res += i;
        }
    }
    return res;
}
int main()
{
    cin >> l >> r;
    cout << f(r) - f(l - 1) << endl;
    return 0;
}