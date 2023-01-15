#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s;
    int x, ans = 0;
    cin >> x >> s;
    for (int i = 0; i < s.size(); i++)
    {
        ans = ans * x + ((s[i] >= '0' && s[i] <= '9') ? s[i] - '0' : s[i] - 'A' + 10);
    }
    cout << ans << "\n";
    return 0;
}