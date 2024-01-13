#include <algorithm>
#include <iostream>
#include <set>
#include <unordered_map>
using namespace std;
int opt[100005], t, c, ans, now, x;
unordered_map<int, int> pos, ts[6];
set<int> pre, suf[6];
int main()
{
    cin >> t >> c;
    for (int i = 1; i <= t; i++)
    {
        cin >> x;
        pos[x] = 1;
    }
    for (int i = 1; i <= c; i++)
    {
        char ch;
        cin >> ch;
        if (ch == 'L')
        {
            opt[i] = -1, now--;
        }
        else if (ch == 'R')
        {
            opt[i] = 1, now++;
        }
        else
        {
            if (pos[now + 2] == 1)
            {
                suf[5].insert(now + 2), ts[5][now + 2]++;
            }
            if (pos[now + 1] == 1)
            {
                suf[4].insert(now + 1), ts[4][now + 1]++;
            }
            if (pos[now] == 1)
            {
                suf[3].insert(now), ts[3][now]++;
            }
            if (pos[now - 1] == 1)
            {
                suf[2].insert(now - 1), ts[2][now - 1]++;
            }
            if (pos[now - 2] == 1)
            {
                suf[1].insert(now - 2), ts[1][now - 2]++;
            }
        }
    }
    ans = suf[3].size(), now = 0;
    for (int i = 1; i <= c; i++)
    {
        if (opt[i] == 0)
        {
            ts[1][now - 2]--, ts[2][now - 1]--, ts[4][now + 1]--, ts[5][now + 2]--;
            if (ts[1][now - 2] == 0)
            {
                suf[1].erase(now - 2);
            }
            if (ts[2][now - 1] == 0)
            {
                suf[2].erase(now - 1);
            }
            if (ts[4][now + 1] == 0)
            {
                suf[4].erase(now + 1);
            }
            if (ts[5][now + 2] == 0)
            {
                suf[5].erase(now + 2);
            }
            x = pre.size() + suf[2].size();
            ans = max(ans, x);
            x = pre.size() + suf[4].size();
            ans = max(ans, x);
            if (pos[now] == 1)
            {
                pre.insert(now);
                suf[5].erase(now), suf[4].erase(now), suf[3].erase(now), suf[2].erase(now), suf[1].erase(now);
            }
        }
        else if (opt[i] == -1)
        {
            x = pre.size() - pre.count(now) + suf[4].size() - suf[4].count(now) + (pos[now] == 1);
            ans = max(ans, x);
            x = pre.size() + suf[5].size();
            ans = max(ans, x);
            now--;
        }
        else if (opt[i] == 1)
        {
            x = pre.size() - pre.count(now) + suf[2].size() - suf[2].count(now) + (pos[now] == 1);
            ans = max(ans, x);
            x = pre.size() + suf[1].size();
            ans = max(ans, x);
            now++;
        }
    }
    cout << ans << endl;
    return 0;
}
// TAG: 贪心 USACO 模拟 前后缀