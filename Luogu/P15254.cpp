#include <algorithm>
#include <iostream>
using namespace std;
int T, opt, n;
string s, res;
int main()
{
    cin >> T >> opt;
    while (T--)
    {
        cout << "Yes" << endl;
        res.clear();
        cin >> n >> s;
        if (opt == 1)
        {
            for (int i = s.size() - 1, status = 0; i >= 0; i--)
            {
                if (status == 0)
                {
                    res += s[i];
                }
                else
                {
                    res += (s[i] == 'O' ? 'M' : 'O');
                }
                status ^= (res.back() == 'O');
            }
        }
        reverse(res.begin(), res.end());
        cout << res << endl;
    }
    return 0;
}