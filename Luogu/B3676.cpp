#include <cstdio>
using namespace std;
int main()
{
    int k;
    scanf("%d", &k);
    if (k > 2)
    {
        printf("Survivor\n");
    }
    else if (k == 2)
    {
        printf("Tie\n");
    }
    else
    {
        printf("Hunter\n");
    }
    return 0;
}