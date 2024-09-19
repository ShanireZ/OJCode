#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
string s;
long long ans, cnt[30];
int main()
{
    cin >> s;
    for (char c : s)
    {
        ans += ++cnt[c - 'a'];
    }
    cout << ans << endl;
    return 0;
}