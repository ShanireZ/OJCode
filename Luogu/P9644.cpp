#include <algorithm>
#include <iostream>
using namespace std;
string s;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, k;
        cin >> n >> k >> s;
        int l = 1, r = s.size();
        while (l <= r)
        {
            int mid = (l + r) / 2, cnt = 0;
            for (int i = 0; i < (int)s.size(); i++)
            {
                if (s[i] == '1')
                {
                    cnt++, i = i + mid - 1;
                }
            }
            cnt <= k ? r = mid - 1 : l = mid + 1;
        }
        cout << l << endl;
    }
    return 0;
}