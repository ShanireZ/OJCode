#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
string s, f = "friend";
int p[1000005], cnt, ans;
int main()
{
    cin >> s;
    int pos = s.find(f, 0);
    while (pos != string::npos)
    {
        p[++cnt] = pos;
        if (pos == s.size() - 1)
        {
            break;
        }
        pos = s.find(f, pos + 1);
    }
    int now = 1;
    while (now <= cnt)
    {
        if (now < cnt && p[now + 1] - p[now] <= 8)
        {
            now++;
        }
        ans++, now++;
    }
    cout << ans << endl;
    return 0;
}