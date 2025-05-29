#include <algorithm>
#include <iostream>
using namespace std;
string s;
int main()
{
    cin >> s;
    int cnt = 0;
    for (int i = (int)s.size() - 1; i >= 0; i--)
    {
        int now = ((s[i] - '0' - cnt) % 10 + 10) % 10;
        cnt += now;
    }
    cout << cnt + (int)s.size() << endl;
    return 0;
}