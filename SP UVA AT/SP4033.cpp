#include <iostream>
#include <string>
using namespace std;
int trie[50][100005][15];
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, trig = 0, pos = 0;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            string s;
            cin >> s;
            int now = 0, status = 0;
            for (int j = 0; j < s.size(); j++)
            {
                int id = s[j] - '0';
                if (trie[t][now][id] == 0)
                {
                    trie[t][now][id] = ++pos;
                    if (j == s.size() - 1)
                    {
                        status = 1;
                    }
                }
                now = trie[t][now][id];
                if (trie[t][now][14])
                {
                    trig = 1;
                }
            }
            if (trie[t][now][14] || status == 0)
            {
                trig = 1;
            }
            trie[t][now][14]++;
        }
        if (trig)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }
    return 0;
}