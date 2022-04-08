#include <iostream>
#include <string>
using namespace std;
int n, m, pos, trie[500005][30];
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
            int id = s[j] - 'a';
            if (trie[now][id] == 0)
            {
                trie[now][id] = ++pos;
            }
            now = trie[now][id];
        }
        trie[now][29] = 1;
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
        if (trig == 0)
        {
            cout << "WRONG" << endl;
        }
        else if (trie[now][29])
        {
            cout << "OK" << endl;
            trie[now][29] = 0;
        }
        else
        {
            cout << "REPEAT" << endl;
        }
    }
    return 0;
}