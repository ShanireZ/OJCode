#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int p[20000005], mx, mid, pos, ans;
char s[20000005];
string str;
void manacher()
{
    for (int i = 0; i <= pos; i++)
    {
        p[i] = (i < mx ? min(p[mid * 2 - i], mx - i) : 1);
        while (i + p[i] <= pos && i - p[i] >= 0 && s[i + p[i]] == s[i - p[i]])
        {
            p[i]++;
        }
        if (i + p[i] > mx)
        {
            mx = i + p[i], mid = i;
        }
        ans = max(ans, p[i] - 1);
    }
}
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        cin >> str;
        pos = ans = mx = mid = 0;
        for (int i = 0; i < (int)str.size(); i++)
        {
            s[++pos] = '#';
            s[++pos] = str[i];
        }
        s[++pos] = '#';
        manacher();
        cout << ans << endl;
    }
    return 0;
}
// TAG: manacher 最长回文子串