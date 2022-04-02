#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<int> ids[1000005];
int ch[1000005][26];
//最大需要1e6空间左右，可枚举每个单词的长度，发现单词长度都为5时，需要空间最多
int main()
{
    int n, m, cnt;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int l;
        cin >> l;
        for (int j = 1; j <= l; j++)
        {
            string s;
            cin >> s;
            int now = 0;
            for (int k = 0; k < s.size(); k++)
            {
                int id = s[k] - 'a';
                if (ch[now][id] == 0)
                {
                    ch[now][id] = ++cnt;
                }
                now = ch[now][id];
            }
            if (ids[now].size() == 0 || ids[now][ids[now].size() - 1] != i)
            {
                ids[now].push_back(i);
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
            if (ch[now][id] == 0)
            {
                trig = 0;
                break;
            }
            now = ch[now][id];
        }
        if (trig)
        {
            for (int j = 0; j < ids[now].size(); j++)
            {
                cout << ids[now][j] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}