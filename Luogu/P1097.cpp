#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
multiset<int> s;
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        s.emplace(x);
    }
    int now = *s.begin(), cnt = 0;
    for (int x : s)
    {
        if (x == now)
        {
            cnt++;
        }
        else
        {
            cout << now << " " << cnt << endl;
            now = x, cnt = 1;
        }
    }
    cout << now << " " << cnt << endl;
    return 0;
}