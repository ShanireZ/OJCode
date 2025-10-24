#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
struct Node
{
    int id, stu, room, st, ed, vis;
};
Node ns[100005];
int n, pos, sid, rid, pid, dur, t[1005], s[1005][2505], r[1005][2505];
string op, tm;
void cl()
{
    if (t[sid] == 2 || t[sid] == 3)
    {
        for (int j = 0; j <= 2500; j++)
        {
            if (s[sid][j])
            {
                int x = s[sid][j];
                s[sid][j] = r[ns[x].room][j] = 0;
                ns[x].vis = 0;
            }
        }
    }
}
int main()
{
    cin >> n;
    while (n--)
    {
        cin >> op;
        if (op == "reserve")
        {
            int ok = 1;
            cin >> sid >> rid >> tm >> dur;
            if (t[sid] >= 3)
            {
                cout << "FAIL\n";
                continue;
            }
            if (dur > 120)
            {
                t[sid]++, ok = 0, cl();
                cout << "FAIL\n";
                continue;
            }
            int st = stoi(tm.substr(0, 2)) * 60 + stoi(tm.substr(3, 2));
            int ed = st + dur - 1;
            for (int i = st; i <= ed; i++) // 不能和下面一起判断,会漏掉违规次数
            {
                if (s[sid][i])
                {
                    t[sid]++, ok = 0, cl();
                    break;
                }
            }
            for (int i = st; i <= ed; i++)
            {
                if (r[rid][i])
                {
                    ok = 0;
                    break;
                }
            }
            if (ok)
            {
                ns[++pos] = Node{pos, sid, rid, st, ed, 1};
                for (int i = st; i <= ed; i++)
                {
                    s[sid][i] = r[rid][i] = pos;
                }
                cout << "SUCCESS " << pos << '\n';
            }
            else
            {
                cout << "FAIL\n";
            }
        }
        else
        {
            cin >> pid;
            if (ns[pid].vis == 1)
            {
                cout << "SUCCESS\n";
                for (int i = ns[pid].st; i <= ns[pid].ed; i++)
                {
                    s[ns[pid].stu][i] = r[ns[pid].room][i] = 0;
                }
                ns[pid].vis = 0;
            }
            else
            {
                cout << "FAIL\n";
            }
        }
    }
    return 0;
}