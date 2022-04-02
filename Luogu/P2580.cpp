#include <iostream>
#include <string>
using namespace std;
struct Node
{
    int ch[30], vis;
};
Node ns[500005];
int n, m, pos;
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
            if (ns[now].ch[id] == 0)
            {
                ns[now].ch[id] = ++pos;
            }
            now = ns[now].ch[id];
        }
    }
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        string s;
        cin >> s;
        int now = 0, ans = 1;
        for (int j = 0; j < s.size(); j++)
        {
            int id = s[j] - 'a';
            if (ns[now].ch[id] == 0)
            {
                ans = 0;
                break;
            }
            now = ns[now].ch[id];
        }
        if (ans == 0)
        {
            cout << "WRONG" << endl;
        }
        else if (ns[now].vis == 0)
        {
            ns[now].vis = 1;
            cout << "OK" << endl;
        }
        else
        {
            cout << "REPEAT" << endl;
        }
    }
    return 0;
}