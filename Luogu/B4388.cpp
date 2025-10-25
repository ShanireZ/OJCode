#include <algorithm>
#include <iostream>
#include <map>
#include <set>
using namespace std;
struct Node
{
    string from, to;
    int t;
    bool operator<(const Node &oth) const
    {
        if (t == oth.t)
        {
            if (from == oth.from)
            {
                return to < oth.to;
            }
            return from < oth.from;
        }
        return t < oth.t;
    }
};
set<Node> ns[105];
map<string, int> mp;
int n, m, ans;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int c;
        cin >> c;
        while (c--)
        {
            string name;
            cin >> name;
            mp[name] = i;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        string info;
        cin >> info;
        int g = mp[info.substr(0, 2)];
        if (g == 0)
        {
            g = mp[info.substr(0, 2)] = ++m;
        }
        int t = stoi(info.substr(15, 2)) * 60 + stoi(info.substr(18, 2));
        ns[g].insert(Node{info.substr(7, 3), info.substr(11, 3), t});
    }
    for (int i = 1; i <= m; i++)
    {
        ans += ns[i].size();
    }
    cout << ans << endl;
    return 0;
}