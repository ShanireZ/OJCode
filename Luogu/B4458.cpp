#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
int n, ans, s[2005];
set<int> st;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
    }
    for (int i = 1; i <= n; i++)
    {
        st.clear();
        int a = 0, b = 0; // a奇b偶
        for (int j = i; j <= n; j++)
        {
            int sz = st.size();
            st.insert(s[j]);
            if (st.size() == sz)
            {
                continue;
            }
            a += s[j] % 2, b += 1 - s[j] % 2;
            if (a == b)
            {
                ans = max(ans, a + b);
            }
        }
    }
    cout << ans << endl;
    return 0;
}