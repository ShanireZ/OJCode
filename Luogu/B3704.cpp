#include <iostream>
using namespace std;
int main()
{
    int id;
    scanf("%d", &id);
    if (id == 1)
    {
        printf("2000000000 2000000000\n");
    }
    else if (id == 2)
    {
        for (int i = 1; i <= 1000000; i++)
        {
            printf("a");
        }
    }
    else
    {
        printf("100\n");
        for (int i = 1; i <= 100; i++)
        {
            printf("1 ");
        }
    }
    return 0;
}