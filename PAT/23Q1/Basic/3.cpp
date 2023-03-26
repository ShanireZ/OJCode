#include <algorithm>
#include <iostream>
#include <map>
#include <string>
using namespace std;
string s, id, ans = "0000";
map<string, int> mp;
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        cin >> id;
        getline(cin, s), getline(cin, s);
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        int pos = s.find("chatgpt");
        while (pos != string::npos)
        {
            mp[id] = mp[id] + 1;
            pos = s.find("chatgpt", pos + 1);
        }
        if (mp[ans] < mp[id])
        {
            ans = id;
        }
    }
    cout << ans << " " << mp[ans];
    return 0;
}