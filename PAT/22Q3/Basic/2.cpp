#include <iostream>
#include <set>
using namespace std;
set<long long> s;
int main()
{
    long long m, k, x = 0;
    cin >> m >> k;
    for (int i = 1; i <= m; i++)
    {
        char ch;
        cin >> ch;
        x = (ch == 'A') ? x / 4 : x * 8 + 1;
        if (x <= k)
        {
            s.insert(x);
        }
    }
    cout << s.size();
    return 0;
}