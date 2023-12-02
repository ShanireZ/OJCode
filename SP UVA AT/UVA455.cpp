#include <algorithm>
#include <iostream>
using namespace std;
string s, fz;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        cin >> s;
        int sz = s.size();
        for (int len = 1; len <= sz; len++)
        {
            if (sz % len != 0)
            {
                continue;
            }
            fz = s.substr(0, len);
            int pos = s.find(fz), cnt = 0;
            while (pos != string::npos)
            {
                cnt++, pos = s.find(fz, pos + len);
            }
            if (cnt == sz / len)
            {
                cout << len << endl;
                break;
            }
        }
        if (T)
        {
            cout << endl;
        }
    }
    return 0;
}
// TAG: 字符串匹配