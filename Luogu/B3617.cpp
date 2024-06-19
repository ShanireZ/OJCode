#include <algorithm>
#include <iostream>
using namespace std;
string s, res;
int nums[3005];
int main()
{
    cin >> s;
    int pos = 0;
    for (char c : s)
    {
        int x = c - '0';
        for (int i = 3; x; i--)
        {
            nums[pos + i] = x % 2;
            x /= 2;
        }
        pos += 3;
    }
    for (int i = pos; i > 0; i -= 4)
    {
        int now = 0;
        for (int j = 0, base = 1; j < 4 && i - j > 0; j++, base *= 2)
        {
            now += nums[i - j] * base;
        }
        if (now < 10)
        {
            res.insert(res.begin(), now + '0');
        }
        else
        {
            res.insert(res.begin(), now - 10 + 'a');
        }
    }
    while (res[0] == '0' && res.size() > 1)
    {
        res.erase(res.begin());
    }
    cout << res << endl;
    return 0;
}