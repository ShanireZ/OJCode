#include <algorithm>
#include <iostream>
using namespace std;
struct Node
{
    int a, b, c, id;
    bool operator<(const Node &oth) const
    {
        if (c == oth.c)
        {
            if (b == oth.b)
            {
                return a < oth.a;
            }
            return b < oth.b;
        }
        return c < oth.c;
    }
};
Node ns[500005];
int main()
{
    int n;
    cin >> n;
    long long ans1 = 0, p = 0;
    for (int i = 1; i <= n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a > b)
        {
            swap(a, b);
        }
        if (b > c)
        {
            swap(b, c);
        }
        if (a > b)
        {
            swap(a, b);
        }
        ns[i] = Node{a, b, c, i};
        long long x = a * a * a / 4;
        if (x > ans1)
        {
            ans1 = x, p = i;
        }
    }
    long long ans2 = ans1;
    sort(ns + 1, ns + n + 1);
    int now = 1;
    while (now < n)
    {
        while (ns[now].c != ns[now + 1].c || ns[now].b != ns[now + 1].b)
        {
            now++;
        }
        long long x = min(ns[now].a + ns[now + 1].a, ns[now].b);
        x = x * x * x / 4;
        if (x > ans2)
        {
            ans2 = x, p = now;
        }
        now++;
    }
    if (ans1 != ans2)
    {
        cout << 1 << endl;
        cout << ns[p].id << " " << ns[p + 1].id << endl;
        cout << ans2 << endl;
    }
    else
    {
        cout << 0 << endl;
        cout << p << endl;
        cout << ans1 << endl;
    }
    return 0;
}