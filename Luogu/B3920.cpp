#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
string s;
vector<int> pp;
int main()
{
    cin >> s;
    int pos = s.find("player"), ans = 0;
    while (pos != string::npos)
    {
        pp.push_back(pos);
        pos = s.find("player", pos + 1);
    }
    pos = s.find("Genshin");
    while (pos != string::npos)
    {
        ans += pp.end() - upper_bound(pp.begin(), pp.end(), pos);
        pos = s.find("Genshin", pos + 1);
    }
    cout << ans << endl;
    return 0;
}