#include <iostream>
#include <string>
#include <map>
using namespace std;
map<string, int> m;
string s[1005];
int main()
{
    ios::sync_with_stdio(false);
    int n, p = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string op, a, b;
        cin >> op;
        if (op == "touch")
        {
            cin >> a;
            if (m[a] == 0)
            {
                m[a] = ++p;
                s[p] = a;
            }
        }
        else if (op == "rm")
        {
            cin >> a;
            if (m[a] != 0)
            {
                s[m[a]] = "";
                m[a] = 0;
            }
        }
        else if (op == "ls")
        {
            for (int i = 1; i <= n; i++)
            {
                if (s[i] != "")
                {
                    cout << s[i] << endl;
                }
            }
        }
        else if (op == "rename")
        {
            cin >> a >> b;
            if (m[a] != 0 && m[b] == 0)
            {
                s[m[a]] = b;
                m[b] = m[a];
                m[a] = 0;
            }
        }
    }
    return 0;
}