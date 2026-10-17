#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
// 最高位情況數 = (位數不足情況數) + (位數正好時 100....000 ~ n 情況數)
string n, s1, s2;
int main()
{
    cin >> n;
    long long p10[105] = {1}, mod = 20091119, ans = 0, len = n.size();
    for (int i = 1; i <= 100; i++)
    {
        p10[i] = p10[i - 1] * 10 % mod;
    }
    for (int i = 1; i < len; i++)
    {
        ans = (ans + 9 * p10[(i - 1) / 2]) % mod;
    }
    long long hlen = len / 2;
    if (len % 2 == 0)
    {
        for (int i = 0; i < hlen; i++)
        {
            long long num = n[i] - '0';
            // 第一位為x時只能選1-x，後面的可以選0~x
            // 假設第3位為x，選0~x-1時後續隨意搭配，選x時還得看後續情況
            ans = (ans + (num - (i == 0)) * p10[hlen - i - 1]) % mod;
        }
        s1 = n.substr(0, hlen), s2 = n.substr(hlen);
    }
    else
    {
        for (int i = 0; i <= hlen; i++)
        {
            long long num = n[i] - '0';
            ans = (ans + (num - (i == 0)) * p10[hlen - i]) % mod;
        }
        s1 = n.substr(0, hlen), s2 = n.substr(hlen + 1);
    }
    reverse(s1.begin(), s1.end());
    cout << (ans + (s1 <= s2)) % mod << endl;
    return 0;
}
// TAG: 數位DP 迴文