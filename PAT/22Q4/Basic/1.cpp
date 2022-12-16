#include <iostream>
#include <string>
using namespace std;
string s;
int main()
{
    int n, cnt = 0;
    cin >> n;
    while (getline(cin, s))
    {
        int ed = s.find("#"); // 以#结束
        if (ed != string::npos)
        {
            s = s.substr(0, ed);
        }
        int pos = s.find("(zhangsheng)");
        while (pos != string::npos)
        {
            cnt++, pos = s.find("(zhangsheng)", pos + 1);
        }
        if (ed != string::npos)
        {
            break;
        }
    }
    cout << cnt << " ";
    if (cnt >= n)
    {
        cout << "True\n";
    }
    else
    {
        cout << "False\n";
    }
    return 0;
}