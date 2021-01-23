#include <bits/stdc++.h>
using namespace std;

int main()
{
    char equal[251];
    memset(equal,0,sizeof(equal));
    int i = 0, j, k, num, total = 0;
    while((equal[i] = getchar()) != '\n')
    {
        i++;
    }
    for(j = 0; j < i; j = k + 1)
    {
        num = 0;
        for(k = j; k < i; k++)
        {
            if(equal[k] >= '0' && equal[k] <= '9')
            {
                num = num * 10 + equal[k] - '0';
            }else
            {
                break;
            }
        }
        total += num;
    }
    cout << total;
    return 0;
}
