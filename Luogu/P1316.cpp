#include <iostream>
#include <algorithm>
using namespace std;
int caps[100005];
int a, b;
bool check(int dis) //比標準距離大或等於標準距離，說明這個瓶蓋可以選
{
    int groups = 1;
    int pos = 1;
    for (int i = 2; i <= a; i++)
    {
        if (caps[i] - caps[pos] >= dis)
        {
            groups++;
            pos = i;
        }
    }
    return groups >= b; //如果可選取的瓶蓋總數比規定大或者和規定相等，說明可以提升標準
}
int main()
{

    cin >> a >> b;
    for (int i = 1; i <= a; i++)
    {
        cin >> caps[i];
    }
    sort(caps + 1, caps + a + 1);
    int l = 0, r = caps[a] - caps[1];
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (check(mid)) //可提升標準
        {
            l = mid + 1;
        }
        else //降低標準
        {
            r = mid - 1;
        }
    }
    cout << r;
    return 0;
}