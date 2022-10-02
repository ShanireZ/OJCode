#include <iostream>
#include <string>
using namespace std;
int days[15] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int main()
{
    string s;
    cin >> s;
    int ans = 100, a = s[0] - '0', b = s[1] - '0', c = s[3] - '0', d = s[4] - '0';
    for (int i = 1; i <= 12; i++)
    {
        int cnt = 4 - (a == i / 10) - (b == i % 10);
        for (int j = 1; j <= days[i]; j++)
        {
            ans = min(ans, cnt - (c == j / 10) - (d == j % 10));
        }
    }
    cout << ans << endl;
    return 0;
}