#include <iostream>
using namespace std;
int dp[46000000];
struct Bond
{
    int p, v;
};
Bond bd[15];
int main()
{
    int s, n, d;
    cin >> s >> n >> d;
    for (int i = 1; i <= d; i++)
    {
        cin >> bd[i].p >> bd[i].v;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= d; j++)
        {
            for (int k = bd[j].p; k <= s; k++)
            {
                dp[k] = max(dp[k], dp[k - bd[j].p] + bd[j].v);
            }
        }
        s += dp[s];
    }
    cout << s << endl;
    return 0;
}