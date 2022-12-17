#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>
using namespace std;
vector<string> rs[1005];
queue<string> q[1005];
map<string, int> nid;
string names[1005];
int cost[30], cnt[30], n, pos;
pair<int, int> count(string a, string b)
{
    memset(cnt, 0, sizeof(cnt));
    pair<int, int> ans;
    int d1 = a[0] * 10 + a[1] - 528, d2 = b[0] * 10 + b[1] - 528;
    int h1 = a[3] * 10 + a[4] - 528, h2 = b[3] * 10 + b[4] - 528;
    int m1 = a[6] * 10 + a[7] - 528, m2 = b[6] * 10 + b[7] - 528;
    ans.second = ((d2 - d1) * 24 + h2 - h1) * 60 + m2 - m1; // 计算时间
    ans.first = (60 - m1) * cost[h1] + m2 * cost[h2];       // 计费
    h1++, h2--;
    for (int i = 0; i < 24; i++)
    {
        cnt[i] += (i >= h1) + (i <= h2);
    }
    d1++, d2--;
    for (int i = 0; i < 24; i++)
    {
        cnt[i] += d2 - d1 + 1, ans.first += cost[i] * cnt[i] * 60;
    }
    return ans;
}
int main()
{
    for (int i = 0; i < 24; i++)
    {
        cin >> cost[i];
    }
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string name, times, status;
        cin >> name >> times >> status;
        if (nid[name] == 0)
        {
            nid[name] = ++pos, names[pos] = name;
        }
        int id = nid[name];
        rs[id].push_back(times + char('0' + (status == "on-line")));
    }
    string month = rs[1][0].substr(0, 2);
    for (int i = 1; i <= pos; i++)
    {
        sort(rs[i].begin(), rs[i].end());
        for (int j = 1; j < int(rs[i].size()); j++)
        {
            if (rs[i][j - 1][11] == '1' && rs[i][j][11] == '0')
            {
                q[i].push(rs[i][j - 1].substr(3, 8));
                q[i].push(rs[i][j].substr(3, 8));
            }
        }
    }
    sort(names + 1, names + 1 + pos);
    for (int i = 1; i <= pos; i++)
    {
        int id = nid[names[i]];
        if (int(q[id].size()) == 0)
        {
            continue;
        }
        cout << names[i] << " " << month << "\n";
        int tot = 0;
        while (q[id].size())
        {
            string a = q[id].front();
            q[id].pop();
            string b = q[id].front();
            q[id].pop();
            cout << a << " " << b << " ";
            pair<int, int> now = count(a, b);
            printf("%d $%d.%02d\n", now.second, now.first / 100, now.first % 100);
            tot += now.first;
        }
        printf("Total amount: $%d.%02d\n", tot / 100, tot % 100);
    }
    return 0;
}