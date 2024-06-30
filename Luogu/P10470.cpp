#include <algorithm>
#include <iostream>
using namespace std;
int v[100005], chs[1000005][26];
string s;
int main()
{
    int n, m, root = 1, pos = 1;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
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
    for (int i = 1; i <= m; i++)
    {
        cin >> s;
        int now = root, res = 0;
        for (char c : s)
        {
            if (chs[now][c - 'a'] == 0)
            {
                break;
            }
            now = chs[now][c - 'a'], res += v[now];
        }
        cout << res << '\n';
    }
    return 0;
}
// TAG: Trie字典树 贪心