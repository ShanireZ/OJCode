#include <algorithm>
#include <iostream>
using namespace std;
struct Node
{
    int id;
    double v;
    bool operator<(const Node &oth) const
    {
        if (v == oth.v)
        {
            return id < oth.id;
        }
        return v > oth.v;
    }
};
Node ns[105];
int read()
{
    int ans = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        ans = ans * 10 + ch - '0';
        ch = getchar();
    }
    return ans;
}
int main()
{
    int n = read(), k = read();
    for (int i = 1; i <= n; i++)
    {
        ns[i].id = i;
        for (int j = 1; j <= k; j++)
        {
            ns[i].v += read();
        }
        ns[i].v /= k;
    }
    sort(ns + 1, ns + 1 + n);
    cout << ns[1].id << "\n"
         << ns[2].id << "\n";
    return 0;
}