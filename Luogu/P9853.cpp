#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
string s;
int all[200005], pos, n, q;
int main()
{
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> s;
        int px = s.find('x'), pe = s.find('=');
        int a = stoi(s.substr(0, px));
        int b = stoi(s.substr(px + 1, pe - px - 1));
        int c = stoi(s.substr(pe + 1));
        int x = (c - b) / a;
        all[++pos] = x;
    }
    sort(all + 1, all + pos + 1);
    pos = unique(all + 1, all + pos + 1) - all - 1;
    for (int i = 1; i <= q; i++)
    {
        int l, r;
        cin >> l >> r;
        int p1 = lower_bound(all + 1, all + pos + 1, l) - all;
        int p2 = upper_bound(all + 1, all + pos + 1, r) - all;
        cout << p2 - p1 << endl;
    }
    return 0;
}