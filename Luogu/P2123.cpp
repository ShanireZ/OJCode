#include <iostream>
#include <algorithm>
using namespace std;
struct Hand
{
    long long a, b, power;
};
Hand hands[20005];
bool cmp(Hand x, Hand y)
{
    //min(ai,bj) ≤ min(aj,bi)
    //优先比较power大小，当power都为负时，按左手从小到大;当power都为正时，按右手从大到小
    if (x.power != y.power)
    {
        return x.power < y.power;
    }
    else if (x.power <= 0)
    {
        return x.a < y.a;
    }
    else
    {
        return x.b > y.b;
    }
}
int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        int n;
        cin >> n;
        for (int j = 1; j <= n; j++)
        {
            cin >> hands[j].a >> hands[j].b;
            //当a > b时,power为1 a = b时,power为0 a < b时,power为-1
            if (hands[j].a != hands[j].b)
            {
                hands[j].power = (hands[j].a - hands[j].b) / abs(hands[j].a - hands[j].b);
            }
        }
        sort(hands + 1, hands + 1 + n, cmp);
        long long c = 0;
        long long total = 0;
        for (int j = 1; j <= n; j++)
        {
            total += hands[j].a;
            c = max(c, total) + hands[j].b;
        }
        cout << c << endl;
    }
    return 0;
}