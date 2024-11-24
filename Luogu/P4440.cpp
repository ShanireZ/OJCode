#include <algorithm>
#include <iostream>
using namespace std;
string s;
int q, cnt[50005][30];
int main()
{
    cin >> s >> q;
    for (int i = 0; i < (int)s.size(); i++)
    {
        for (int j = 0; j < 26; j++)
        {
            cnt[i + 1][j] = cnt[i][j];
        }
        cnt[i + 1][s[i] - 'a']++;
    }
    while (q--)
    {
        int a, b, c, d, ok = 1;
        cin >> a >> b >> c >> d;
        for (int j = 0; j < 26; j++)
        {
            if (cnt[b][j] - cnt[a - 1][j] != cnt[d][j] - cnt[c - 1][j])
            {
                ok = 0;
                break;
            }
        }
        cout << (ok ? "DA" : "NE") << endl;
    }
    return 0;
}