#include <cmath>
#include <iostream>
using namespace std;
int main()
{
    long long x, z;
    double c;
    scanf("%lld %lld %lf", &x, &z, &c);
    printf("%lld\n", (long long)ceil((x - z * 2) / c));
    return 0;
}