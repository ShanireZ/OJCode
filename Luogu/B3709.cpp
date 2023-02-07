#include <algorithm>
#include <iostream>
using namespace std;
int fact[20] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800};
int main()
{
    // todo 2*(n!-n)  2*(n!-2n) 2
    int n;
    scanf("%d", &n);
    printf("%d %d 2\n", 2 * (fact[n] - n), 2 * (fact[n] - 2 * n));
    return 0;
}