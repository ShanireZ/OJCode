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
    for (int i = 0; i <= (int)s.size(); i++) // 求C組合數
    {
        c[i][0] = c[i][i] = 1;
        for (int j = 1; j < i; j++)
        {
            c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
        }
    }
    for (int i = 0; i < (int)s.size(); i++)
    {
        for (int j = 0; j < s[i] - '0'; j++) // 比當前數小的放在當前位，後方可以隨意排列，因為有重複的所以要去重。
        {
            if (cnt[j] == 0)
            {
                continue;
            }
            long long len = (int)s.size() - i - 1, sum = 1;
            for (int k = 0; k <= 9; k++) // 隨意排列+去重參考題解1
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