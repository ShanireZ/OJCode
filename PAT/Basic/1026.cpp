#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    b = round((b - a) / 100.0);
    int h = b / 3600, m = b % 3600 / 60, s = b % 60;
    printf("%02d:%02d:%02d\n", h, m, s);
    return 0;
}