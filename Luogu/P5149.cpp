#include <iostream>
#include <string>
using namespace std;
int n, pos, bt[100005], trie[500005][60];
int lowbit(int x)
{
    return x & -x;
}
void edit(int x)
{
    while (x <= n)
    {
        bt[x]++;
        x += lowbit(x);
    }
}
int query(int x)
{
    int ans = 0;
    while (x)
    {
        ans += bt[x];
        x -= lowbit(x);
    }
    return ans;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        int now = 0;
        for (int j = 0; j < s.size(); j++)
        {
            int id = s[j] - 'A';
            if (trie[now][id] == 0)
            {
                trie[now][id] = ++pos;
            }
            now = trie[now][id];
        }
        trie[now][59] = i;
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        int now = 0;
        for (int j = 0; j < s.size(); j++)
        {
            int id = s[j] - 'A';
            now = trie[now][id];
        }
        now = trie[now][59];
        ans += query(n) - query(now);
        edit(now);
    }
    cout << ans << endl;
    return 0;
}