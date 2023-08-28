#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
string s, chs;
int main()
{
    cin >> s;
    int t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0;
    for (int i = 0; i < (int)s.size(); i++)
    {
        if (s[i] == ',' || i == (int)s.size() - 1)
        {
            if ((int)chs.size() >= 6 && (int)chs.size() <= 12 && t1 + t2 + t3 >= 2 && t4 && t5 == 0)
            {
                cout << chs << endl;
            }
            string().swap(chs), t1 = t2 = t3 = t4 = t5 = 0;
        }
        else
        {
            chs += s[i];
            if (s[i] >= '0' && s[i] <= '9')
            {
                t1 = 1;
            }
            else if (s[i] >= 'a' && s[i] <= 'z')
            {
                t2 = 1;
            }
            else if (s[i] >= 'A' && s[i] <= 'Z')
            {
                t3 = 1;
            }
            else if (s[i] == '!' || s[i] == '#' || s[i] == '@' || s[i] == '$')
            {
                t4 = 1;
            }
            else
            {
                t5 = 1;
            }
        }
    }
    return 0;
}
// TAG: 字符串 模拟 GESP3