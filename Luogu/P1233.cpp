#include <iostream>
#include <algorithm>
using namespace std;
struct Wood
{
    int l, w;
    int check;
};
Wood woods[5005];
bool cmp(Wood a, Wood b)
{
    if (a.l == b.l)
    {
        return a.w > b.w;
    }
    return a.l > b.l;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> woods[i].l >> woods[i].w;
    }
    sort(woods + 1, woods + 1 + n, cmp);
    int wait = 0;
    for (int i = 1; i <= n; i++)
    {
        if (woods[i].check == 0)
        {
            woods[i].check = 1;
            int cur = woods[i].w;
            for (int j = i + 1; j <= n; j++)
            {
                if (woods[j].w <= cur && woods[j].check == 0)
                {
                    woods[j].check = 1;
                    cur = woods[j].w;
                }
            }
            wait++;
        }
    }
    cout << wait;
    return 0;
}