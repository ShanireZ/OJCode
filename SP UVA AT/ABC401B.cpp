#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int n, ans = 0, status = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        if (s == "login")
        {
            status = 1;
        }
        else if (s == "logout")
        {
            status = 0;
        }
        else if (status == 0 && s == "private")
        {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}