#include <bits/stdc++.h>
using namespace std;

int main()
{
    char a[202], b[202];
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    int i = 1, j, k = 0, out[202];
    memset(out,0,sizeof(out));
    while((a[i] = getchar()) != '\n')
    {
        i++;
    }
    i = 1;
    while((b[i] = getchar()) != '\n')
    {
        i++;
    }
    for(j = 1; j < i; j++)
    {
        if(a[j] == b[j])
        {
            out[k] = j;
            k++;
        }
    }
    for(i = 0; i < k; i++)
    {
        cout << out[i] << " ";
    }
    return 0;
}