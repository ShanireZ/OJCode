#include <iostream>
#include <string>
using namespace std;
string s;
bool judge(int st, int ed)
{
    for (int l1 = st; l1 < ed; l1++)
    {
        for (int r1 = l1; r1 < ed; r1++)
        {
            for (int l2 = r1 + 1; l2 <= ed; l2++)
            {
                for (int r2 = l2; r2 <= ed; r2++)
                {
                    long long x = stoll(s.substr(l1, r1 - l1 + 1));
                    long long y = stoll(s.substr(l2, r2 - l2 + 1));
                    if (y % x == 0)
                    {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}
int main()
{
    cin >> s;
    long long ans = 0, sz = s.size();
    if (sz > 9) // 长度大于9的子串必然是好的
    {
        ans = (sz - 9 + 1) * (sz - 9) / 2;
    }
    for (int i = 0; i < (int)s.size() - 1; i++) // 枚举子串起点
    {
        int maxd = min(9, (int)s.size() - i); // 以i为起点的子串最大长度
        for (int d = 2; d <= maxd; d++)       // 枚举子串长度
        {
            if (judge(i, i + d - 1)) // 当前长度和maxd以内后续长度都可以
            {
                ans += maxd - d + 1;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}