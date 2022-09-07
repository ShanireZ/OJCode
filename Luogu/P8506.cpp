#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n, cnt = 0;
    cin >> n;
    string s;
    getline(cin, s);
    for (int i = 1; i <= n; i++)
    {
        getline(cin, s);
        int p, t = 0;
        for (int j = 0; j < int(s.size()); j++)
        {
            if (s[j] != ' ')
            {
                if (s[j] == '#')
                {
                    p = j, t = 1;
                }
                break;
            }
        }
        if (t == 0 || (p + 1 < int(s.size()) && s[p + 1] != ' '))
        {
            continue;
        }
        for (int j = p + 2; j < int(s.size()); j++)
        {
            if (s[j] != ' ' && s[j] != '\n')
            {
                cnt++;
                break;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}