#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
struct Node
{
    char v;
    int ch[26], vis;
};
Node ns[500005];
int main()
{
    int n, m, root = 1, pos = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        int now = root;
        for (int j = 0; j < s.size(); j++)
        {
            if (ns[now].ch[s[j] - 'a'])
            {
                now = ns[now].ch[s[j] - 'a'];
            }
            else
            {
                ns[now].ch[s[j] - 'a'] = ++pos;
                ns[pos].v = s[j];
                now = pos;
            }
        }
        ns[now].vis = 1;
    }
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        string s;
        cin >> s;
        int now = root, trig = 1;
        for (int j = 0; j < s.size(); j++)
        {
            if (ns[now].ch[s[j] - 'a'])
            {
                now = ns[now].ch[s[j] - 'a'];
            }
            else
            {
                trig = 0;
                break;
            }
        }
        if (trig == 0)
        {
            cout << "WRONG" << endl;
        }
        else
        {
            if (ns[now].vis == 1)
            {
                ns[now].vis = 5;
                cout << "OK" << endl;
            }
            else
            {
                cout << "REPEAT" << endl;
            }
        }
    }
    return 0;
}