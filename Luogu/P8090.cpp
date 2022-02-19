#include <iostream>
using namespace std;
int cnt[30];
char all[15], ans[15];
int main()
{
    for (int i = 1; i <= 9; i++)
    {
        cin >> all[i];
        cnt[all[i] - 'A']++;
    }
    int green = 0, yellow = 0;
    for (int i = 1; i <= 9; i++)
    {
        cin >> ans[i];
        if (ans[i] == all[i])
        {
            green++;
            cnt[ans[i] - 'A']--;
            ans[i] = '#';
        }
    }
    for (int i = 1; i <= 9; i++)
    {
        if (ans[i] == '#')
        {
            continue;
        }
        if (cnt[ans[i] - 'A'])
        {
            yellow++;
            cnt[ans[i] - 'A']--;
        }
    }
    cout << green << endl
         << yellow;
    return 0;
}