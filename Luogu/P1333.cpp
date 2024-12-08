#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
map<string, int> mp;
vector<int> to[500005], jd;
int pos, st, ed, cnt, vis[500005];
string a, b;
void dfs(int now, int from)
{
    vis[now] = 1, cnt++;
    for (int nxt : to[now])
    {
        if (nxt == from || vis[nxt])
        {
            continue;
        }
        dfs(nxt, now);
    }
}
int main()
{
    while (cin >> a >> b)
    {
        if (mp[a] == 0)
        {
            mp[a] = ++pos;
        }
        if (mp[b] == 0)
        {
            mp[b] = ++pos;
        }
        int ai = mp[a], bi = mp[b];
        to[ai].push_back(bi), to[bi].push_back(ai);
    }
    if (pos == 0)
    {
        cout << "Possible" << endl;
        return 0;
    }
    for (int i = 1; i <= pos; i++)
    {
        if (to[i].size() % 2 == 1)
        {
            jd.push_back(i);
        }
    }
    dfs(1, 0);
    if (cnt == pos && (jd.size() == 0 || jd.size() == 2))
    {
        cout << "Possible" << endl;
    }
    else
    {
        cout << "Impossible" << endl;
    }
    return 0;
}