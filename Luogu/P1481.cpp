#include <algorithm>
#include <iostream>
using namespace std;
int chs[150005][26], v[150005], ans;
void dfs(int now)
{
    ans = max(ans, v[now]);
    for (int i = 0; i < 26; i++)
    {
        if (chs[now][i] != 0)
        {
            v[chs[now][i]] += v[now];
            dfs(chs[now][i]);
        }
    }
}
int main()
{
    int n, root = 1, pos = 1;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        int now = root;
        for (char c : s)
        {
            if (chs[now][c - 'a'] == 0)
            {
                chs[now][c - 'a'] = ++pos;
            }
            now = chs[now][c - 'a'];
        }
        v[now]++;
    }
    dfs(root);
    cout << ans << endl;
    return 0;
}
// TAG: Trie字典树 贪心 搜索