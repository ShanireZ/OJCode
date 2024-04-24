#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
string s;
int ans;
int main()
{
    cin >> s;
    for (int i = 0; i < (int)s.size(); i++)
    {
        for (int j = i; j < (int)s.size(); j++)
        {
            string ss = s.substr(i, j - i + 1);
            int cnt[30] = {0}, ok = 1;
            for (char c : ss)
            {
                int id = c - 'a';
                cnt[id]++;
                if (cnt[id] > (j - i + 1) / 2)
                {
                    ok = 0;
                    break;
                }
            }
            ans += ok;
        }
    }
    cout << ans << endl;
    return 0;
}