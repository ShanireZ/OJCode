#include <iostream>
using namespace std;
int main()
{
    int x;
    scanf("%d", &x);
    x = (x % 2023 + 2023) % 2023;
    printf("%d", x);
    return 0;
}