#include <iostream>
using namespace std;
int ysh[1005], dp[1005];
void init(int s)
{
    for (int i = 2; i <= s; i++)
    {
        ysh[i] = 1;
    }
    while (s)
    {
        for (int i = 2; i * i <= s; i++)
        {
            if (s % i == 0)
            {
                ysh[s] += i;
                if (s / i != i)
                {
                    ysh[s] += s / i;
                }
            }
        }
        s--;
    }
}
int main()
{
    int s;
    cin >> s;
    init(s);
    for (int i = 1; i <= s; i++)
    {
        for (int j = s; j >= i; j--)
        {
            dp[j] = max(dp[j], dp[j - i] + ysh[i]);
        }
    }
    cout << dp[s] << endl;
    return 0;
}
