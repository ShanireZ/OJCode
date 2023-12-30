#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
string s1, s2;
int ans[5000];
int main()
{
    cin >> s1 >> s2;
    reverse(s1.begin(), s1.end()), reverse(s2.begin(), s2.end());
    for (int i = 0; i < (int)s1.size(); i++)
    {
        for (int j = 0; j < (int)s2.size(); j++)
        {
            ans[i + j] += (s1[i] - '0') * (s2[j] - '0');
        }
    }
    int pos = s1.size() + s2.size();
    for (int i = 0; i <= pos; i++)
    {
        if (ans[i] >= 10)
        {
            ans[i + 1] += ans[i] / 10;
            ans[i] %= 10;
        }
    }
    while (pos > 0 && ans[pos] == 0)
    {
        pos--;
    }
    for (int i = pos; i >= 0; i--)
    {
        cout << ans[i];
    }
    return 0;
}
// TAG: 高精度乘法