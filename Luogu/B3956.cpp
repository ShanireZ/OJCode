#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int n, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        char ch;
        cin >> ch;
        if (ch >= 'a' && ch <= 'z')
        {
            ans += ch - 'a' + 1;
        }
        else
        {
            ans += -ch;
        }
    }
    cout << ans << endl;
    return 0;
}