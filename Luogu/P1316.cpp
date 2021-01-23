#include <iostream>
#include <algorithm>
using namespace std;
int caps[100005];
int a, b;
bool check(int dis) //比标准距离大或等于标准距离，说明这个瓶盖可以选
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
    return groups >= b; //如果可选取的瓶盖总数比规定大或者和规定相等，说明可以提升标准
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
        if (check(mid)) //可提升标准
        {
            l = mid + 1;
        }
        else //降低标准
        {
            r = mid - 1;
        }
    }
    cout << r;
    return 0;
}