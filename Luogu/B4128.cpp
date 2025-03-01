#include <iostream>
using namespace std;
int main()
{
    char c;
    int ans = 0;
    while (cin >> c)
    {
        ans += c;
    }
    cout << ans << endl;
    return 0;
}