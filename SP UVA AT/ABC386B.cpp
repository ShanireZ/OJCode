#include <algorithm>
#include <iostream>
using namespace std;
int ans;
int main()
{
    string s;
    cin >> s;
    char pre = 'x';
    for (char c : s)
    {
        if (pre == '0' && pre == c)
        {
            pre = 'x';
            continue;
        }
        ans++, pre = c;
    }
    cout << ans << endl;
    return 0;
}