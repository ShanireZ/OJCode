#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        long long x, ans = 0;
        string s;
        cin >> x >> s;
        for (char c : s)
        {
            ans = ans * x + (c >= '0' && c <= '9' ? c - '0' : c - 'A' + 10);
        }
        cout << ans << endl;
    }
    return 0;
}