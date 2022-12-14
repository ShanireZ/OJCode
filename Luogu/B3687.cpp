#include <cmath>
#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int n, now = 1;
    scanf("%d", &n);
    while (n >= now)
    {
        printf("%d\n", now);
        n -= now++;
    }
    return 0;
}