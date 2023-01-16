#include <iostream>
using namespace std;
int main()
{
    long long a, b, c;
    scanf("%lld %lld %lld", &a, &b, &c);
    (a % c || b % c) ? printf("-1") : printf("%lld", (a / c) * (b / c));
    return 0;
}