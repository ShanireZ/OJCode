#include <iostream>
#include <string>
using namespace std;
struct Node
{
    string s;
    int id;
};
Node ns[100005];
int status[100005];
int main()
{
    int n, pos = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        status[i] = status[i - 1];
        if (s == "CapsLock")
        {
            status[i] = !status[i - 1];
        }
        else
        {
            ns[++pos].s = s;
            ns[pos].id = i;
        }
    }
    int x = status[n], q;
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        long long t;
        cin >> t;
        int now = (t - 1) / pos % 2 * x;
        t = t % pos;
        if (t == 0)
        {
            t = pos;
        }
        now = (status[ns[t].id - 1] + now) % 2;
        if (now == 0)
        {
            cout << ns[t].s << endl;
        }
        else
        {
            for (int j = 0; j < int(ns[t].s.size()); j++)
            {
                if (ns[t].s[j] <= 'z' && ns[t].s[j] >= 'a')
                {
                    cout << char(ns[t].s[j] - 'a' + 'A');
                }
                else
                {
                    cout << char(ns[t].s[j] + 'a' - 'A');
                }
            }
            cout << endl;
        }
    }
    return 0;
}