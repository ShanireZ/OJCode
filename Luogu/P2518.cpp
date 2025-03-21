#include <algorithm>
#include <iostream>
using namespace std;
long long ans, c[55][55], cnt[10];
string s;
int main()
{
    cin >> s;
    for (int i = 0; i < (int)s.size(); i++)
    {
        cnt[s[i] - '0']++;
    }
    for (int i = 0; i <= (int)s.size(); i++) // 求C组合数
    {
        c[i][0] = c[i][i] = 1;
        for (int j = 1; j < i; j++)
        {
            c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
        }
    }
    for (int i = 0; i < (int)s.size(); i++)
    {
        for (int j = 0; j < s[i] - '0'; j++) // 比当前数小的放在当前位，后方可以随意排列，因为有重复的所以要去重。
        {
            if (cnt[j] == 0)
            {
                continue;
            }
            long long len = (int)s.size() - i - 1, sum = 1;
            for (int k = 0; k <= 9; k++) // 随意排列+去重参考题解1
            {
                long long x = cnt[k] - (j == k);
                sum *= c[len][x];
                len -= x;
            }
            ans += sum;
        }
        cnt[s[i] - '0']--;
    }
    cout << ans << endl;
    return 0;
}