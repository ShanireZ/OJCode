#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int ans[505];
string s1, s2;
int main()
{
    cin >> s1 >> s2;
    for (int i = (int)s1.size() - 1, j = 0; i >= 0; i--, j++)
    {
        ans[j] = s1[i] - '0';
    }
    for (int i = (int)s2.size() - 1, j = 0; i >= 0; i--, j++)
    {
        ans[j] += s2[i] - '0';
    }
    int pos = max(s1.size(), s2.size());
    for (int i = 0; i <= pos; i++)
    {
        if (ans[i] >= 10)
        {
            ans[i] -= 10, ans[i + 1]++;
        }
    }
    pos -= (ans[pos] == 0);
    for (int i = pos; i >= 0; i--)
    {
        cout << ans[i];
    }
    return 0;
}
// TAG: 高精度加法