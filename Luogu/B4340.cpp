#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int t;
    scanf("%d", &t);
    int h1 = t / 60 / 10, h2 = t / 60 % 10, t1 = t % 60 / 10, t2 = t % 60 % 10;
    printf("|%d|%d|:|%d|%d|\n", h1, h2, t1, t2);
    return 0;
}