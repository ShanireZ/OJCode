#include <algorithm>
#include <iostream>
#include <map>
#include <string>
using namespace std;
map<string, int> mp;
string s;
int main()
{
    int n, k, v;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> s >> v;
        mp[s] = v;
    }
    getline(cin, s);
    while (k--)
    {
        getline(cin, s);
        int st = 0, p1 = s.find('{'), p2;
        while (p1 != (int)string::npos)
        {
            p2 = s.find('}', p1);
            cout << s.substr(st, p1 - st) << mp[s.substr(p1 + 1, p2 - p1 - 1)];
            st = p2 + 1, p1 = s.find('{', st);
        }
        cout << s.substr(st) << endl;
    }
    return 0;
}