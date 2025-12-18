#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
string s, op = "ACGT?*";
int n, ans, pos = 1, trie[505][6], vis[505][505];
void init()
{
    int now = 1;
    for (char ch : s)
    {
        int x = 0;
        while (op[x] != ch)
        {
            x++;
        }
        if (trie[now][x] == 0)
        {
            trie[now][x] = (x == 5 ? now : ++pos);
        }
        now = trie[now][x];
    }
}
int dfs(int step, int now)
{
    if (now == pos)
    {
        return 1;
    }
    if (step == (int)s.size() || vis[step][now])
    {
        return 0;
    }
    vis[step][now] = 1;
    int x = 0;
    while (op[x] != s[step])
    {
        x++;
    }
    if (trie[now][x] && dfs(step + 1, trie[now][x]))
    {
        return 1;
    }
    if (trie[now][4] && dfs(step + 1, trie[now][4]))
    {
        return 1;
    }
    if (trie[now][5] && dfs(step + 1, trie[now][5]))
    {
        return 1;
    }
    return 0;
}
int main()
{
    cin >> s >> n;
    init();
    for (int i = 1; i <= n; i++)
    {
        cin >> s;
        ans += dfs(0, 1);
        memset(vis, 0, sizeof(vis));
    }
    cout << n - ans << endl;
    return 0;
}