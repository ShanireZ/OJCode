#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int n;
    scanf("%d", &n);
    printf("%d %d %lld\n", 8, 12 * (n - 2), 6ll * (n - 2) * (n - 2));
    return 0;
}