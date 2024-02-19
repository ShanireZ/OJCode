#include <algorithm>
#include <iostream>
#include <map>
#include <string>
using namespace std;
map<string, int> mp;
string trs[105], s;
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> s >> trs[i];
        mp[s] = i;
    }
    char c;
    s.clear(), trs[0] = "UNK";
    while (cin >> c)
    {
        if (c < 'a' || c > 'z')
        {
            if (s.size())
            {
                cout << trs[mp[s]];
                s.clear();
            }
            cout << c;
            continue;
        }
        s += c;
    }
    if (s.size())
    {
        cout << trs[mp[s]] << endl;
    }
    return 0;
}