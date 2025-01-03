#include <algorithm>
#include <iostream>
using namespace std;
string s, t;
int main()
{
    int k;
    cin >> k >> s >> t;
    if (t.size() > s.size())
    {
        swap(s, t);
    }
    int ls = s.size(), lt = t.size(), cnt = 0;
    if (ls - lt > 1)
    {
        cout << "No" << endl;
        return 0;
    }
    for (int i = 0; i < ls; i++)
    {
        if (s[i] != t[i])
        {
            cnt++;
            if (cnt > 1)
            {
                break;
            }
            if (ls != lt)
            {
                ls--, s.erase(i, 1);
            }
        }
    }
    cout << (cnt <= 1 ? "Yes" : "No") << endl;
    return 0;
}