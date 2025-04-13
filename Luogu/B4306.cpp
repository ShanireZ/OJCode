#include <algorithm>
#include <iostream>
using namespace std;
char mt[55][55], ct;
int main()
{
    int n;
    cin >> n >> ct;
    for (int i = 0; i <= n / 2; i++)
    {
        char nct = ct - (n / 2 - i);
        for (int j = 0; j < n / 2 - i; j++)
        {
            mt[i][j] = '.';
        }
        for (int j = n / 2; j >= n / 2 - i; j--)
        {
            mt[i][j] = nct - (n / 2 - j);
        }
        for (int j = n / 2; j <= n / 2 + i; j++)
        {
            mt[i][j] = nct - (j - n / 2);
        }
        for (int j = n / 2 + i + 1; j < n; j++)
        {
            mt[i][j] = '.';
        }
    }
    for (int i = n - 1; i > n / 2; i--)
    {
        char nct = ct - (i - n / 2);
        for (int j = 0; j < n / 2 - (n - i - 1); j++)
        {
            mt[i][j] = '.';
        }
        for (int j = n / 2; j >= n / 2 - (n - i - 1); j--)
        {
            mt[i][j] = nct - (n / 2 - j);
        }
        for (int j = n / 2; j <= n / 2 + (n - i - 1); j++)
        {
            mt[i][j] = nct - (j - n / 2);
        }
        for (int j = n / 2 + (n - i - 1) + 1; j < n; j++)
        {
            mt[i][j] = '.';
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << mt[i][j];
        }
        cout << endl;
    }
    return 0;
}