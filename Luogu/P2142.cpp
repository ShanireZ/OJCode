#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
string s1, s2;
int ans[11000];
int main()
{
    cin >> s1 >> s2;
    if (s2.size() > s1.size() || (s2.size() == s1.size() && s2 > s1))
    {
        swap(s1, s2);
        cout << '-';
    }
    for (int i = (int)s1.size() - 1, j = 0; i >= 0; i--, j++)
    {
        ans[j] = s1[i] - '0';
    }
    for (int i = (int)s2.size() - 1, j = 0; i >= 0; i--, j++)
    {
        ans[j] -= s2[i] - '0';
    }
    int pos = s1.size();
    for (int i = 0; i < pos; i++)
    {
        if (ans[i] < 0)
        {
            ans[i] += 10, ans[i + 1]--;
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
// TAG: 高精度减法