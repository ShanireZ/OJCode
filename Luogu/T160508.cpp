#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
    int x;
    scanf("%d", &x);
    if (x < 60)
    {
        x = sqrt(x) * 10;
    }

    if (x >= 90)
    {
        printf("4.0");
    }
    else if (x >= 60 && x < 90)
    {
        printf("%.1f", 4.0 - (90 - x) * 0.1);
    }
    else
    {
        printf("0.0");
    }
    return 0;
}