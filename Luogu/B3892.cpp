#include <algorithm>
#include <iostream>
#include <map>
#include <string>
using namespace std;
string s;
map<int, int> mp;
int main()
{
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> s;
        int px = s.find('x'), pe = s.find('=');
        int a = stoi(s.substr(0, px));
        int b = stoi(s.substr(px + 1, pe - px - 1));
        int c = stoi(s.substr(pe + 1));
        int x = (c - b) / a;
        mp[x] = 1;
    }
    for (int i = 1; i <= q; i++)
    {
        int l, r, ans = 0;
        cin >> l >> r;
        for (int j = l; j <= r; j++)
        {
            ans += mp[j];
        }
        cout << ans << endl;
    }
    return 0;
}