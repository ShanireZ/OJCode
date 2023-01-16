#include <iostream>
using namespace std;
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int ans = 1;
        for (int j = 1; j <= i; j++)
        {
            ans *= i;
            printf("%d ^ %d = %d ", i, j, ans);
        }
        printf("\n");
    }
    return 0;
}