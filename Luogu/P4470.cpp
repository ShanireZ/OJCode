#include <iostream>
#include <string>
using namespace std;
string s, all[55], keybord[5] = {"*", "***ABCDE", "FGHIJKLM", "NOPQRSTU", "VWXYZ***"};
int status[30], n;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> all[i];
    }
    cin >> s;
    for (int i = 1; i <= n; i++)
    {
        if (s.size() >= all[i].size())
        {
            continue;
        }
        else if (s == all[i].substr(0, s.size()))
        {
            int id = all[i][s.size()] - 'A';
            status[id] = 1;
        }
    }
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 0; j < keybord[i].size(); j++)
        {
            int id = keybord[i][j] - 'A';
            if (keybord[i][j] != '*' && status[id])
            {
                cout << keybord[i][j];
            }
            else
            {
                cout << "*";
            }
        }
        cout << endl;
    }
    return 0;
}