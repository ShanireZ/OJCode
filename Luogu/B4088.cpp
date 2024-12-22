#include <algorithm>
#include <iostream>
using namespace std;
string res, str;
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> str;
        int hw = 1;
        for (int l = 0, r = str.size() - 1; l < r; l++, r--)
        {
            if (str[l] != str[r])
            {
                hw = 0;
                break;
            }
        }
        if (hw && (str.size() > res.size() || (str.size() == res.size() && str > res)))
        {
            res = str;
        }
    }
    cout << res << endl;
    return 0;
}