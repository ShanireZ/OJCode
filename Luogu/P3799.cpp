#include <iostream>
#include <algorithm>
using namespace std;
int cnt[5005];
long long c2[100005];
int main()
{
    int n, mod = 1e9 + 7;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int len;
        cin >> len;
        cnt[len]++;
    }
    for (int i = 1; i <= n; i++)
    {
        c2[i] = i * (i - 1) / 2 % mod;
    }
    long long tot = 0;
    for (int i = 1; i <= 5000; i++) //枚举2根 等长 长棍
    {
        if (cnt[i] < 2)
        {
            continue;
        }
        long long ans1 = c2[cnt[i]], ans2 = 0; //cnt[i]个选2个
        for (int j = 1; j <= i / 2; j++)       //枚举两根短棍
        {
            if (i == j * 2) //从cnt[j]个选2个
            {
                ans2 = (ans2 + c2[cnt[j]]) % mod;
            }
            else //cnt[j]个选1个  cnt[i-j]个选1个
            {
                ans2 = (ans2 + cnt[j] * cnt[i - j] % mod) % mod;
            }
        }
        tot = (tot + ans1 * ans2 % mod) % mod;
    }
    cout << tot;
    return 0;
}