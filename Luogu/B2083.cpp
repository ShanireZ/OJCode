#include <iomanip>
#include <iostream>
using namespace std;
int main()
{
    int a, b, f;
    char c;
    cin >> a >> b >> c >> f;
    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j <= b; j++)
        {
            if (f == 0 && i > 1 && i < a && j > 1 && j < b)
            {
                cout << " ";
            }
            else
            {
                cout << c;
            }
        }
        cout << endl;
    }
    return 0;
}