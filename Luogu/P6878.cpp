#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int n, k, pos[3][200005];
string s;
int main()
{
    cin >> n >> k >> s;
    for (int i = 0; i < (int)s.size(); i++)
    {
        if (s[i] == 'J')
        {
            pos[0][++pos[0][0]] = i;
        }
        else if (s[i] == 'O')
        {
            pos[1][++pos[1][0]] = i;
        }
        else
        {
            pos[2][++pos[2][0]] = i;
        }
    }
    int ans = 0x3f3f3f3f;
    for (int i = 1; i <= pos[0][0] - k + 1; i++)
    {
        int st = pos[0][i], ed = pos[0][i + k - 1];
        int p = lower_bound(pos[1] + 1, pos[1] + pos[1][0] + 1, ed) - pos[1];
        if (p + k - 1 > pos[1][0])
        {
            continue;
        }
        ed = pos[1][p + k - 1];
        p = lower_bound(pos[2] + 1, pos[2] + pos[2][0] + 1, ed) - pos[2];
        if (p + k - 1 > pos[2][0])
        {
            continue;
        }
        ed = pos[2][p + k - 1];
        ans = min(ans, ed - st + 1 - k * 3);
    }
    if (ans == 0x3f3f3f3f)
    {
        ans = -1;
    }
    cout << ans << "\n";
    return 0;
}
// TAG: 贪心 二分