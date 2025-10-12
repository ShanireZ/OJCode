#include <algorithm>
#include <iostream>
using namespace std;
long long l, r, ans;
long long f(long long ed) // 从0开始每4个数一区,区域内有趣数要么是i和i+3,要么是i+1和i+2
{
    long long res = 0, lmt = ed / 4 * 4;
    for (int i = 0; i + 3 < lmt; i += 4) // 处理前方区域
    {
        res += i + (i + 3);
    }
    int x = lmt, cnt = 0; // 处理最后一个区域
    while (x)
    {
        cnt += x % 2;
        x /= 2;
    }
    for (int i = lmt; i <= ed; i++) // 如果i内1的个数是奇数,则i和i+3是有趣数,否则i+1和i+2是有趣数
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