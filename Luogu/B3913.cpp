#include <algorithm>
#include <iostream>
using namespace std;
int b[10] = {100, 150, 300, 400, 1000};
int main()
{
    int a;
    cin >> a;
    for (int i = 0; i < 5; i++)
    {
        if (a <= b[i])
        {
            cout << b[i] << endl;
            break;
        }
    }
    return 0;
}