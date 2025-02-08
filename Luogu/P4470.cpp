#include <algorithm>
#include <iostream>
using namespace std;
string kb[10] = {"", "***ABCDE", "FGHIJKLM", "NOPQRSTU", "VWXYZ***"}, str;
int n, now, pos = 1, vis[30], ns[5005][30];
int main()
{
    cin >> n;
    while (n--)
    {
        cin >> str;
        now = 1;
        for (int i = 0; i < (int)str.size(); i++)
        {
            int x = str[i] - 'A';
            if (ns[now][x] == 0)
            {
                ns[now][x] = ++pos;
            }
            now = ns[now][x];
        }
    }
    cin >> str;
    now = 1;
    for (int i = 0; i < (int)str.size(); i++)
    {
        int x = str[i] - 'A';
        if (ns[now][x] == 0)
        {
            break;
        }
        now = ns[now][x];
    }
    for (int j = 0; j < 26; j++)
    {
        vis[j] = ns[now][j];
    }
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cout << ((kb[i][j] == '*' || vis[kb[i][j] - 'A'] == 0) ? '*' : kb[i][j]);
        }
        cout << endl;
    }
    return 0;
}