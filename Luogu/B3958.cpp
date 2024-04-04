#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        string s1, s2;
        cin >> s1 >> s2;
        if (s1.size() == s2.size())
        {
            int cnt = 0;
            for (int i = 0; i <= (int)s1.size(); i++)
            {
                cnt += (s1[i] != s2[i]);
            }
            cout << (cnt <= 1 ? "similar" : "not similar") << endl;
        }
        else
        {
            if (s1.size() < s2.size())
            {
                swap(s1, s2);
            }
            int ok = 1;
            for (int i = 0; i < (int)s1.size(); i++)
            {
                string s = s1;
                s.erase(i, 1);
                if (s == s2)
                {
                    cout << "similar" << endl;
                    ok = 0;
                    break;
                }
            }
            if (ok)
            {
                cout << "not similar" << endl;
            }
        }
    }
    return 0;
}