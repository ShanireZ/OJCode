#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
multiset<int> st;
int n, m, k, cnt, lst[200005], nxt[200005];
int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        int c;
        cin >> c;
        nxt[lst[c]] = i;
        lst[c] = i, nxt[i] = 1000000;
    }
    for (int i = 1; i <= k; i++)
    {
        st.emplace(1000000);
    }
    for (int i = 1; i <= n; i++)
    {
        auto pos = st.lower_bound(i);
        if (*pos != i)
        {
            pos = --st.end();
            cnt++;
        }
        st.erase(pos);
        st.emplace(nxt[i]);
    }
    cout << cnt << endl;
    return 0;
}