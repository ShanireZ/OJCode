#include <iostream>
#include <string>
using namespace std;
string x, ans;
int main()
{
    cin >> x;
    while (x != "99999")
    {
        int now = x[0] - '0' + x[1] - '0';
        if (now)
        {
            ans = (now % 2 ? "left" : "right");
        }
        cout << ans << " " << x.substr(2) << "\n";
        cin >> x;
    }
    return 0;
}