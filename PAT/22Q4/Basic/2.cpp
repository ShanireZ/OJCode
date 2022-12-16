#include <iostream>
using namespace std;
int fib[30005];
int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    fib[0] = 0, fib[1] = 1;
    int p = 1;
    while (fib[p] + fib[p - 1] <= b)
    {
        p++;
        fib[p] = fib[p - 1] + fib[p - 2];
    }
    printf("max( %d^2 + %d^2 ) = %d\n", fib[p - 1], fib[p], fib[p] * fib[p] + fib[p - 1] * fib[p - 1]);
    return 0;
}