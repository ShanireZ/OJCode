#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
using namespace std;
struct Node
{
    string name;
    double sig;
    bool operator<(const Node &oth) const
    {
        if (sig == oth.sig)
        {
            return name < oth.name;
        }
        return sig > oth.sig;
    }
};
Node ns[100005];
int s[25];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> ns[i].name;
        double tot = 0, sig = 0;
        for (int j = 1; j <= m; j++)
        {
            cin >> s[j];
            tot += s[j];
        }
        tot /= m;
        for (int j = 1; j <= m; j++)
        {
            sig += (tot - s[j]) * (tot - s[j]);
        }
        ns[i].sig = sqrt(sig / m);
    }
    sort(ns + 1, ns + 1 + n);
    for (int i = 1; i <= min(n, 20); i++)
    {
        cout << ns[i].name << endl;
    }
    return 0;
}