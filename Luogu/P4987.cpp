#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
string s;
int p[2000005], vis[1000005];
int main()
{
    int n, l, cnt = 0;
    cin >> n >> l >> s;
    s += s;
    for (int i = 0, mid = 0, mx = 0; i < n * 2; i++)
    {
        p[i] = (i < mx ? min(p[2 * mid - i], mx - i) : 1);
        while (i - p[i] >= 0 && i + p[i] < n * 2 && s[i - p[i]] == s[i + p[i]])
        {
            p[i]++;
        }
        if (i + p[i] > mx)
        {
            mx = i + p[i], mid = i;
        }
        if (p[i] * 2 - 1 >= l)
        {
            if (i >= n && vis[i - n] == 0)
            {
                cnt++, vis[i - n] = 1;
            }
            else if (i < n && vis[i] == 0)
            {
                cnt++, vis[i] = 1;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}
// TAG: Manacher 最长回文子串