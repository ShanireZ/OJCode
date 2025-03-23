#include <algorithm>
#include <iostream>
using namespace std;
string s, rec[105];
int n, pos, ans, cnt[105];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> s;
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        int ok = 1;
        for (int i = 1; i <= pos; i++)
        {
            if (rec[i] == s)
            {
                cnt[i]++, ok = 0;
                break;
            }
        }
        if (ok)
        {
            rec[++pos] = s;
            cnt[pos] = 1;
        }
    }
    for (int i = 1; i <= pos; i++)
    {
        if (cnt[i] > cnt[ans])
        {
            ans = i;
        }
    }
    cout << rec[ans] << endl;
    return 0;
}