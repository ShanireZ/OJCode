#include <iostream>
#include <string>
using namespace std;
int pos[30];
int main()
{
    int ans = 1;
    for (int i = 1; i <= 26; i++)
    {
        char ch;
        cin >> ch;
        pos[ch - 'a'] = i;
    }
    string m;
    cin >> m;
    int pre = 0;
    for (int i = 0; i < m.size(); i++)
    {
        int now = pos[m[i] - 'a'];
        if (now <= pre)
        {
            ans++;
        }
        pre = now;
    }
    cout << ans << endl;
    return 0;
}