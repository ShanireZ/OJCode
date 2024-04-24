#include <algorithm>
#include <iostream>
using namespace std;
struct Stu
{
    int id, cn, ma, en, rk;
    int sum, tca, mxca;
    bool operator<(const Stu &oth) const
    {
        if (sum == oth.sum)
        {
            if (tca == oth.tca)
            {
                return mxca > oth.mxca;
            }
            return tca > oth.tca;
        }
        return sum > oth.sum;
    }
};
Stu s[10005];
int rk[100005];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i].cn >> s[i].ma >> s[i].en;
        s[i].id = i, s[i].sum = s[i].cn + s[i].ma + s[i].en;
        s[i].tca = s[i].cn + s[i].ma, s[i].mxca = max(s[i].cn, s[i].ma);
    }
    sort(s + 1, s + n + 1);
    for (int i = 1; i <= n; i++)
    {
        if (s[i].sum == s[i - 1].sum && s[i].tca == s[i - 1].tca && s[i].mxca == s[i - 1].mxca)
        {
            rk[s[i].id] = rk[s[i - 1].id];
        }
        else
        {
            rk[s[i].id] = i;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << rk[i] << "\n";
    }
    return 0;
}