#include <algorithm>
#include <iostream>
using namespace std;
int chs[4000005][2], bin[40], ans; // 此题ai范围为int_max
void dfs(int a, int b, int res)
{
    if (chs[a][0] == 0 && chs[a][1] == 0)
    {
        ans = max(ans, res);
        return;
    }
    int ok = 1;
    if (chs[a][0] && chs[b][1])
    {
        dfs(chs[a][0], chs[b][1], res * 2 + 1), ok = 0;
    }
    if (chs[a][1] && chs[b][0])
    {
        dfs(chs[a][1], chs[b][0], res * 2 + 1), ok = 0;
    }
    if (ok && chs[a][0] && chs[b][0])
    {
        dfs(chs[a][0], chs[b][0], res * 2);
    }
    if (ok && chs[a][1] && chs[b][1])
    {
        dfs(chs[a][1], chs[b][1], res * 2);
    }
}
int main()
{
    int n, root = 1, pos = 1;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x, p = 0;
        cin >> x;
        while (x) // 转化二进制
        {
            bin[++p] = x % 2;
            x /= 2;
        }
        for (int j = 31, now = root; j >= 1; j--) // 建01Trie
        {
            if (chs[now][bin[j]] == 0)
            {
                chs[now][bin[j]] = ++pos;
            }
            now = chs[now][bin[j]];
            bin[j] = 0;
        }
    }
    dfs(root, root, 0);
    cout << ans << endl;
    return 0;
}
// TAG: 01Trie 贪心