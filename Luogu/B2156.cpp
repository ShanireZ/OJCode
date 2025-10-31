#include <iostream>
using namespace std;
string s, ans;
int ok = 1;
int main()
{
    while (cin >> s)
    {
        if (s.back() == '.')
        {
            s.pop_back(), ok = 0;
        }
        if (s.size() > ans.size())
        {
            ans = s;
        }
        if (ok == 0)
        {
            break;
        }
    }
    cout << ans << endl;
    return 0;
}