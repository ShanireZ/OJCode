#include <algorithm>
#include <iostream>
using namespace std;
string s, tmp;
int p[1005];
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int k, ans = 0;
        cin >> s >> k;
        for (int i = 1; i <= k; i++)
        {
            cin >> p[i];
            p[i]--;
        }
        p[0] = -1, p[k + 1] = s.size() - 1;
        for (int i = 1; i <= k + 1; i++)
        {
            tmp = s.substr(p[i - 1] + 1, p[i] - p[i - 1]);
            ans += (tmp.find("respect") != string::npos);
        }
        cout << ans << endl;
    }
    return 0;
}