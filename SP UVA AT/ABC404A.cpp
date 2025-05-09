#include <algorithm>
#include <iostream>
using namespace std;
int vis[30];
int main()
{
    char ch;
    while (cin >> ch)
    {
        vis[ch - 'a'] = 1;
    }
    for (int i = 0; i < 26; i++)
    {
        if (vis[i] == 0)
        {
            cout << char(i + 'a') << endl;
            break;
        }
    }
    return 0;
}