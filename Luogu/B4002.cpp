#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
int pf[1005], n, a;
set<int> s;
int main()
{
    for (int i = 1; i < 1000; i++)
    {
        pf[i] = i * i;
        for (int j = 1; j <= i && pf[i] + pf[j] <= 1000000; j++)
        {
            s.insert(pf[i] + pf[j]);
        }
    }
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        s.find(a) != s.end() ? cout << "Yes\n" : cout << "No\n";
    }
    return 0;
}