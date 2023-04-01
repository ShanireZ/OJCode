#include <iostream>
using namespace std;
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        long long a, b;
        scanf("%lld %lld", &a, &b);
        while (a && b)
        {
            a = (a < b ? a + 1 : a / 2);
            if (!a)
            {
                break;
            }
            b = (b < a ? b + 1 : b / 2);
        }
        printf("%lld %lld\n", a, b);
    }
    return 0;
}