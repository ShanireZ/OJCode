#include <algorithm>
#include <iostream>
using namespace std;
int n;
string s;
int main()
{
    cin >> n;
    while (n--)
    {
        cin >> s;
        int c0[30] = {0}, c1[30] = {0}, trig0 = 0, trig1 = 0;
        for (int i = 0; i < (int)s.size(); i++)
        {
            i % 2 == 0 ? c1[s[i] - 'a']++ : c0[s[i] - 'a']++;
        }
        if (s.size() % 2 == 1)
        {
            for (int i = 0; i < 26; i++)
            {
                trig0 += (c0[i] % 2), trig1 += (c1[i] % 2);
            }
            int mid = s.size() / 2 + 1;
            if (mid % 2 == 1)
            {
                cout << (trig0 == 0 && trig1 == 1 ? "YES" : "NO") << endl;
            }
            else
            {
                cout << (trig1 == 0 && trig0 == 1 ? "YES" : "NO") << endl;
            }
        }
        else
        {
            for (int i = 0; i < 26; i++)
            {
                trig0 += (c0[i] != c1[i]);
            }
            cout << (trig0 == 0 ? "YES" : "NO") << endl;
        }
    }
    return 0;
}