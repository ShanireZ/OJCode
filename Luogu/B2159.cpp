#include <algorithm>
#include <iostream>
using namespace std;
struct Node
{
    string name;
    double s;
    bool operator<(const Node &oth) const
    {
        if (s == oth.s)
        {
            return name < oth.name;
        }
        return s > oth.s;
    }
};
Node ns[25];
int n;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> ns[i].name >> ns[i].s;
    }
    sort(ns + 1, ns + 1 + n);
    for (int i = 1; i <= n; i++)
    {
        cout << ns[i].name << " " << ns[i].s << endl;
    }
    return 0;
}