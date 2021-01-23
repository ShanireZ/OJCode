#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    char isbn[13];
    int total = 0, num = 1;
    for (int i = 0; i < 13; i++)
    {
        isbn[i] = getchar();
    }
    for (int i = 0; i < 11; i++)
    {
        if (isbn[i] != '-')
        {
            total += (isbn[i] - '0') * num;
            num++;
        }
    }
    total %= 11;
    if ((total == (isbn[12] - '0')) || (total == 10 && isbn[12] == 'X'))
    {
        cout << "Right";
    }
    else
    {
        for (int i = 0; i < 12; i++)
        {
            cout << isbn[i];
        }
        if (total == 10)
        {
            cout << 'X';
        }
        else
        {
            cout << total;
        }
    }
    return 0;
}