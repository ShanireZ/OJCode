#include <algorithm>
#include <iostream>
using namespace std;
string s, fd;
long long p, pos, ans;
int main()
{
    cin >> s >> p;
    while (p--)
    {
        cin >> fd;
        fd = "\"" + fd + "\"";
        pos = s.find(fd, pos);
    }
    pos = s.find(":", pos) + 1;
    while (isdigit(s[pos]))
    {
        ans = ans * 10 + (s[pos] - '0');
        pos++;
    }
    cout << ans << endl;
    return 0;
}