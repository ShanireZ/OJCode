#include <iostream>
using namespace std;
struct Stu
{
    int l, r, no;
};
Stu s[100005];
int main()
{
    int n;
    cin >> n;
    s[0].r = 1;
    for (int i = 2; i <= n; i++)
    {
        int k, p;
        cin >> k >> p;
        if (p == 0) //左
        {
            s[i].l = s[k].l;
            s[i].r = k;
            s[s[k].l].r = i;
            s[k].l = i;
        }
        else //右
        {
            s[i].l = k;
            s[i].r = s[k].r;
            s[s[k].r].l = i;
            s[k].r = i;
        }
    }
    int m;
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        int x;
        cin >> x;
        if (s[x].no == 1)
        {
            continue;
        }
        s[x].no = 1;
        s[s[x].l].r = s[x].r;
        s[s[x].r].l = s[x].l;
    }
    int now = s[0].r;
    while (now != 0)
    {
        cout << now << " ";
        now = s[now].r;
    }
    return 0;
}