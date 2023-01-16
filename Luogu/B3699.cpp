#include <cstring>
#include <iostream>
using namespace std;
char num[20];
int main()
{
    scanf("%s", num);
    long long x = 0, tag = 0;
    for (int i = 0; i < strlen(num); i++)
    {
        x = x * 10 + num[i] - '0';
        tag += (num[i] == '6' && num[i + 1] == '2');
    }
    tag += (x % 62 == 0);
    tag ? printf("Yes") : printf("No");
    return 0;
}