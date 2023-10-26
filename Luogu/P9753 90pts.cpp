#include <iostream>
#include <map>
#include <string>
using namespace std;
map<string, int> cnt;
string s;
int main()
{
    long long n, ans = 0;
    cin >> n;
    cnt[s] = 1;
    for (int i = 1; i <= n; i++)
    {
        char ch;
        cin >> ch;
        if (s.size() && s[s.size() - 1] == ch)
        {
            s.erase(s.size() - 1);
        }
        else
        {
            s.append(1, ch);
        }
        ans += cnt[s];
        cnt[s]++;
    }
    cout << ans << endl;
    return 0;
}
// TAG: 栈 前缀 哈希 离散化