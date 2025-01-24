#include <algorithm>
#include <iostream>
using namespace std;
int rec[10005][4], vis[4], ans[4], pos, opt, tp;
string s;
int trans(char ch)
{
    return ch == 'L' ? 0 : 2;
}
int main()
{
    cin >> s >> tp;
    for (int i = 0; i < (int)s.size(); i++)
    {
        if (s[i] == '(')
        {
            opt = 1, vis[0] = vis[1] = vis[2] = vis[3] = 0;
        }
        else if (s[i] == ')')
        {
            pos++, opt = 0;
            rec[pos][0] = vis[0], rec[pos][1] = vis[1];
            rec[pos][2] = vis[2], rec[pos][3] = vis[3];
        }
        else if (opt == 0)
        {
            if (s[i] == '\'')
            {
                int p = trans(s[i - 1]);
                rec[pos][p] = 0, rec[pos][p + 1] = 1;
            }
            else
            {
                rec[++pos][trans(s[i])] = 1;
            }
        }
        else
        {
            if (s[i] == '\'')
            {
                int p = trans(s[i - 1]);
                vis[p]--, vis[p + 1]++;
            }
            else
            {
                vis[trans(s[i])]++;
            }
        }
    }
    cout << pos << endl;
    if (tp == 1)
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 1, lst = 0; j <= pos; j++)
            {
                rec[j][i] ? lst++ : lst = 0;
                ans[i] = max(ans[i], lst);
            }
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}