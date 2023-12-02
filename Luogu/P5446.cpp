#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int p[1000005], vis[1000005];
string s;
void manacher()
{
    for (int i = 0, mx = 0, mid = 0; i < (int)s.size(); i++)
    {
        p[i] = (i < mx ? min(p[2 * mid - i], mx - i) : 1);
        while (i + p[i] < (int)s.size() && i - p[i] >= 0 && s[i + p[i]] == s[i - p[i]])
        {
            p[i]++;
        }
        if (i + p[i] > mx)
        {
            mx = i + p[i], mid = i;
        }
    }
}
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        cin >> s;
        manacher();
        for (int i = s.size() - 1; i >= 0; i--)
        {
            vis[i] = 0;
            // 要么右侧能到末尾，要么左侧能到开头且右侧能到一个翻转中心
            if (i + p[i] == (int)s.size() || (vis[i + p[i] - 1] && i - p[i] + 1 == 0))
            {
                vis[i] = 1;
            }
        }
        for (int i = 0; i < (int)s.size(); i++)
        {
            if (vis[i])
            {
                cout << i + 1 << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
// TAG: Manacher 最长回文子串