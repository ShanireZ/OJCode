#include <iostream>
#include <string>
using namespace std;
char chs[5] = {'P', 'T', ' '};
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        int ok = 1, id = 0, pos[5] = {0};
        for (int j = 0; j < (int)s.size(); j++)
        {
            if (s[j] != 'A' && s[j] != chs[id])
            {
                ok = 0;
                break;
            }
            if (s[j] == chs[id])
            {
                pos[id++] = j;
            }
        }
        int t = pos[1] - pos[0] - 1;
        if (t == 0 || pos[0] * t != (int)s.size() - pos[1] - 1)
        {
            ok = 0;
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
    return 0;
}