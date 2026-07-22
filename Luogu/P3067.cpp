#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
int a[25], s[2000005], n, pos, ans;
vector<int> delta[60005];
map<int, int> ids;
void dfs1(int now, int dlt, int state)
{
    if (now == n / 2)
    {
        if (ids[dlt] == 0)
        {
            ids[dlt] = ++pos;
        }
        int id = ids[dlt];
        delta[id].push_back(state);
        return;
    }
    dfs1(now + 1, dlt + a[now], state | (1 << now));
    dfs1(now + 1, dlt - a[now], state | (1 << now));
    dfs1(now + 1, dlt, state);
}
void dfs2(int now, int dlt, int state)
{
    if (now == n)
    {
        int id = ids[dlt];
        for (int x : delta[id])
        {
            ans += (s[state | x] == 0);
            s[state | x] = 1;
        }
        return;
    }
    dfs2(now + 1, dlt + a[now], state | (1 << now));
    dfs2(now + 1, dlt - a[now], state | (1 << now));
    dfs2(now + 1, dlt, state);
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    dfs1(0, 0, 0), dfs2(n / 2, 0, 0);
    cout << ans - 1 << endl;
    return 0;
}