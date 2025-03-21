#include <algorithm>
#include <iostream>
using namespace std;
string s;
int main()
{
    cin >> s;
    long long ans = 0, num = 0, pre = 1;
    for (char ch : s)
    {
        if (isdigit(ch))
        {
            num = num * 10 + ch - '0';
        }
        else
        {
            ans += pre * num;
            pre = (ch == '+' ? 1 : -1), num = 0;
        }
    }
    ans += pre * num;
    cout << ans << endl;
    return 0;
}