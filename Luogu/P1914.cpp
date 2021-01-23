#include <string>
#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int n;
    cin >> n;
    char pwd[50];
    int i = 0;
    while (cin >> pwd[i])
    {
        i++;
    }
    for (int j = 0; j < i; j++)
    {
        pwd[j] += (n % 26 - 26);
        if (pwd[j] < 'a')
        {
            pwd[j] += 26;
        }
        cout << pwd[j];
    }
    return 0;
}