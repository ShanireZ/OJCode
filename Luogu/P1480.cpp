#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
string s1, s2;
int main()
{
    cin >> s1 >> s2;
    long long x = stoi(s2), now = 0;
    int pos = 0;
    while (pos < (int)s1.size() && now < x)
    {
        now = now * 10 + (s1[pos] - '0'), pos++;
    }
    for (int i = pos; i < (int)s1.size(); i++)
    {
        cout << now / x;
        now = now % x * 10 + (s1[i] - '0');
    }
    cout << now / x;
    return 0;
}
// TAG: 高精度小数除法