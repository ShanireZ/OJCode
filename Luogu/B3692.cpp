#include <iostream>
#include <map>
#include <queue>
#include <string>
using namespace std;
#define MX 1005
struct Team
{
    int id, tot, cnt;
    bool operator<(const Team oth) const
    {
        if (cnt == oth.cnt)
        {
            if (tot == oth.tot)
            {
                return id < oth.id;
            }
            return tot < oth.tot;
        }
        return cnt > oth.cnt;
    }
};
Team teams[MX];
map<string, int> mp;
string s1, s2, s3, s4, names[MX];
int n, m, k, pos, gd[MX][25], ac[MX][25];
priority_queue<Team> q;
int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m >> k;
    for (int i = 1; i <= k; i++)
    {
        cin >> s1 >> s2 >> s3 >> s4;
        int t = (s1[0] - '0') * 60 + (s1[2] - '0') * 10 + (s1[3] - '0');
        int pid = s2[0] - 'A';
        if (mp[s3] == 0)
        {
            mp[s3] = ++pos;
            teams[pos].id = pos, names[pos] = s3;
        }
        int tid = mp[s3];
        if (ac[tid][pid] == -1 || gd[tid][pid] != 0)
        {
            if (s4[0] == 'T' || s4[0] == 'M')
            {
                cin >> s4 >> s4;
            }
            else if (s4[0] != 'A')
            {
                cin >> s4;
            }
        }
        else
        {
            if (s4[0] == 'A')
            {
                if (t > 240 || (t == 240 && (s1[5] != '0' || s1[6] != '0')))
                {
                    gd[tid][pid] = t + ac[tid][pid] * 20;
                }
                else
                {
                    teams[tid].cnt++, teams[tid].tot += t + ac[tid][pid] * 20;
                    ac[tid][pid] = -1;
                }
            }
            else if (s4[0] == 'T' || s4[0] == 'M')
            {
                cin >> s4 >> s4;
                ac[tid][pid]++;
            }
            else
            {
                cin >> s4;
                ac[tid][pid]++;
            }
        }
    }
    for (int i = 1; i <= pos; i++)
    {
        q.push(teams[i]);
    }
    while (q.size())
    {
        Team now = q.top();
        q.pop();
        cout << names[now.id] << '\n';
        for (int i = 0; i < n; i++)
        {
            if (gd[now.id][i] != 0)
            {
                now.tot += gd[now.id][i], now.cnt++;
                gd[now.id][i] = 0;
                if (q.size() && now.cnt > q.top().cnt || (now.cnt == q.top().cnt && now.tot < q.top().tot) || (now.cnt == q.top().cnt && now.tot == q.top().tot && now.id < q.top().id))
                {
                    q.push(now);
                    break;
                }
            }
        }
    }
    return 0;
}