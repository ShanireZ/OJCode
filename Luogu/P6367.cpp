#include <algorithm>
#include <iostream>
#include <map>
#include <string>
using namespace std;
map<string, int> mp;
int main()
{
    int n, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string name;
        cin >> name;
        if (mp[name] * 2 > i - 1)
        {
            ans++;
        }
        mp[name]++;
    }
    cout << ans << endl;
    return 0;
}