#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
string s;
int cnt[26][26], len;
int main()
{
    cin >> s;
    len = s.size();
    for (int i = 0; i < len - 1; i++)
    {
        int now = s[i] - 'a', nxt = s[i + 1] - 'a';
        cnt[now][nxt]++;
    }
    for (int i = 1; i <= len; i++)
    {
        int now = s.back() - 'a', mx = 0;
        for (int j = 1; j < 26; j++)
        {
            if (cnt[now][j] > cnt[now][mx])
            {
                mx = j;
            }
        }
        s += (char)(mx + 'a');
    }
    cout << s << endl;
    return 0;
}