#include <algorithm>
#include <iostream>
using namespace std;
string dp1[2005], dp2[2005]; // dp1最短 dp2独立最短
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        if (i == 1 || i == 11 || i == 111 || i == 1111)
        {
            dp1[i] = dp2[i] = to_string(i);
        }
        else
        {
            dp1[i] = dp1[i - 1] + "+1";
            dp2[i] = "(" + dp1[i] + ")";
        }
    }
    for (int i = 1; i < n; i++)
    {
        for (int a = 1; a + i <= n; a++) // 非独立长度肯定小于等于独立长度,所以加法只考虑非独立
        {
            if (dp1[a].size() + dp1[i].size() + 1 < dp1[a + i].size())
            {
                dp1[a + i] = dp1[a] + "+" + dp1[i];
            }
            if (dp1[a].size() + dp1[i].size() + 3 < dp2[a + i].size())
            {
                dp2[a + i] = "(" + dp1[a] + "+" + dp1[i] + ")";
            }
        }
        for (int a = 2; a * i <= n; a++) // 乘法只能用独立更新
        {
            if (dp2[a].size() + dp2[i].size() + 1 < dp1[a * i].size())
            {
                dp1[a * i] = dp2[a] + "*" + dp2[i];
            }
            if (dp2[a].size() + dp2[i].size() + 1 < dp2[a * i].size())
            {
                dp2[a * i] = dp2[a] + "*" + dp2[i];
            }
        }
    }
    cout << dp1[n] << endl;
    return 0;
}