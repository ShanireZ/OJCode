#include <iostream>
#include <algorithm>
using namespace std;
struct Round
{
    int a, b, guess;
};
Round rs[105];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> rs[i].a >> rs[i].b >> rs[i].guess;
    }
    int maxcnt = 0;
    for (int i = 1; i <= 3; i++)
    {
        int pos = i, cnt = 0;
        for (int j = 1; j <= n; j++)
        {
            if (rs[j].a == pos)
            {
                pos = rs[j].b;
            }
            else if (rs[j].b == pos)
            {
                pos = rs[j].a;
            }
            if (pos == rs[j].guess)
            {
                cnt++;
            }
        }
        maxcnt = max(maxcnt, cnt);
    }
    cout << maxcnt;
    return 0;
}