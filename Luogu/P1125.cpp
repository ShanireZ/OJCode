#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
    string wd;
    cin >> wd;
    int ch[26] = {0};
    int maxn = -1, minn = 1000;
    for (int i = 0; i < wd.size(); i++) //! 统计字母出现次数
    {
        int id = wd[i] - 'a';
        ch[id]++;
    }
    for (int i = 0; i < 26; i++) //! 统计最大与最小出现次数
    {
        if (ch[i] > 0)
        {
            maxn = max(maxn, ch[i]);
            minn = min(minn, ch[i]);
        }
    }
    int prime[105] = {1, 1}; //! 筛法求质数-质数的倍数都是合数
    for (int i = 2; i <= 50; i++)
    {
        if (prime[i] == 1)
        {
            continue;
        }
        for (int j = 2; i * j <= 100; j++)
        {
            prime[i * j] = 1;
        }
    }
    if (prime[maxn - minn] == 0)
    {
        cout << "Lucky Word" << endl
             << maxn - minn;
    }
    else
    {
        cout << "No Answer" << endl
             << 0;
    }
    return 0;
}