#include <bits/stdc++.h>
using namespace std;

int main()
{
    char art[201];
    memset(art, 0, sizeof(art));
    int i = 0, j, k, minNum = 200, count, pos;
    while ((art[i] = getchar()) != '.')
    {
        i++;
    }
    for (j = 0; j < i; j = k + 1)
    {
        count = 0;
        for (k = j; k < i; k++)
        {
            if (art[k] != ' ')
            {
                count++;
            }
            else
            {
                break;
            }
        }
        if (count < minNum)
        {
            minNum = count;
            pos = k - 1;
        }
    } 
    for (i = pos - minNum + 1; i <= pos; i++)
    {
        cout << art[i];
    }
    return 0;
}