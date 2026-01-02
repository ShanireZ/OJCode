#include <algorithm>
#include <iostream>
using namespace std;
int n, cnt;
string s, ans, res;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> s;
        int pos = s.rfind("####");
        ans = s.substr(pos + 4);
        cin >> s;
        pos = s.find("\\boxed{");
        int pos2 = s.find("}", pos + 7);
        res = s.substr(pos + 7, pos2 - (pos + 7));
        cnt += (ans == res);
    }
    cout << cnt << endl;
    return 0;
}