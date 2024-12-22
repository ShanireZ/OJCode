#include <algorithm>
#include <iostream>
using namespace std;
string str;
int x[15], cnt[15];
int main()
{
    cin >> str;
    for (char ch : str)
    {
        ch -= 3 * (ch == '5' || ch == '9');
        x[ch - '0']++;
    }
    cin >> str;
    for (char ch : str)
    {
        ch -= 3 * (ch == '5' || ch == '9');
        cnt[ch - '0']++;
    }
    int res = 1e9;
    for (int i = 0; i < 9; i++)
    {
        if (x[i] == 0)
        {
            continue;
        }
        res = x[i] > cnt[i] ? 0 : min(res, cnt[i] / x[i]);
    }
    cout << res << endl;
    return 0;
}