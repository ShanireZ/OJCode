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
    for (int i = 0; i < wd.size(); i++) //! 統計字母出現次數
    {
        int id = wd[i] - 'a';
        ch[id]++;
    }
    for (int i = 0; i < 26; i++) //! 統計最大與最小出現次數
    {
        if (ch[i] > 0)
        {
            maxn = max(maxn, ch[i]);
            minn = min(minn, ch[i]);
        }
    }
    int prime[105] = {1, 1}; //! 篩法求質數-質數的倍數都是合數
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