#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
string a, b;
int ans[1000005], pos;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        cin >> a >> b;
        pos = 0;
        int p = a.find(b), cnt = 0;
        while (p != string::npos)
        {
            ans[++pos] = p + 1, cnt++;
            p = a.find(b, p + b.size());
        }
        if (cnt == 0)
        {
            cout << "Not Found\n";
        }
        else
        {
            cout << cnt << "\n";
            for (int i = 1; i <= pos; i++)
            {
                cout << ans[i] << " ";
            }
            cout << "\n";
        }
        if (T)
        {
            cout << "\n";
        }
    }
    return 0;
}
// TAG: 字符串匹配