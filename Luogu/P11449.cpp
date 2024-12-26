#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        if (n <= 10)
        {
            cout << 0 << endl;
            continue;
        }
        int res = 0, sz = to_string(n - 1).size();
        for (int i = 2, st = 45, ed = min(n, 49); i <= sz; i++)
        {
            if (ed >= st)
            {
                res += ed - st + 1;
            }
            st = st * 10 - 5, ed = min(n, ed * 10 + 9);
        }
        cout << res << endl;
    }
    return 0;
}