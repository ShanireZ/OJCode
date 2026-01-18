#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
#define MX 200005
int trie[MX][26], fail[MX], cnt[MX], lst[MX], ans, n, root = 1, pos = 1;
string s[20005];
queue<int> q;
void init(int id)
{
    int now = root;
    for (char ch : s[id])
    {
        int x = ch - 'a';
        if (trie[now][x] == 0)
        {
            trie[now][x] = ++pos;
        }
        now = trie[now][x];
    }
    cnt[now]++;
}
int findpos(int now, int x)
{
    while (now != 0 && trie[now][x] == 0)
    {
        now = fail[now];
    }
    return now == 0 ? root : trie[now][x];
}
void makef()
{
    q.push(root);
    while (q.size())
    {
        int now = q.front();
        q.pop();
        for (int i = 0; i < 26; i++)
        {
            int f = findpos(fail[now], i);
            if (trie[now][i] == 0)
            {
                trie[now][i] = f;
                continue;
            }
            fail[trie[now][i]] = f, q.push(trie[now][i]);
        }
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
        init(i);
    }
    makef();
    for (int i = 1; i <= n; i++)
    {
        int now = root;
        for (char ch : s[i])
        {
            now = trie[now][ch - 'a'];
            int p = now; // 测试s[i]每个前缀+该前缀的所有后缀
            while (p != root && lst[p] != i)
            {
                ans += cnt[p], lst[p] = i; // 避免重复统计
                p = fail[p];
            }
        }
        ans -= 1; // 减去自身
    }
    cout << ans << endl;
    return 0;
}