#include <iostream>
#include <set>
#include <string>
using namespace std;
int pos, n, m, trie[500005][26];
set<int> flag[500005];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int len;
        cin >> len;
        for (int j = 1; j <= len; j++)
        {
            string s;
            cin >> s;
            int now = 0;
            for (int k = 0; k < s.size(); k++)
            {
                int id = s[k] - 'a';
                if (trie[now][id] == 0)
                {
                    trie[now][id] = ++pos;
                }
                now = trie[now][id];
            }
            if (flag[now].lower_bound(i) == flag[now].end())
            {
                flag[now].insert(i);
            }
        }
    }
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        string s;
        cin >> s;
        int now = 0, trig = 1;
        for (int j = 0; j < s.size(); j++)
        {
            int id = s[j] - 'a';
            if (trie[now][id] == 0)
            {
                trig = 0;
                break;
            }
            now = trie[now][id];
        }
        if (trig)
        {
            for (auto it = flag[now].begin(); it != flag[now].end(); it++)
            {
                cout << *it << " ";
            }
        }
        cout << endl;
    }
    return 0;
}