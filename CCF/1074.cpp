/*
    硬解码
*/

#include <iostream>
#include <string>
#include <cmath>
using namespace std;
string str[15] = {"2(0)", "2", "2(2)", "2(2+2(0))", "2(2(2))", "2(2(2)+2(0))", "2(2(2)+2)", "2(2(2)+2+2(0))", "2(2(2+2(0)))", "2(2(2+2(0))+2(0))", "2(2(2+2(0))+2)", "2(2(2+2(0))+2+2(0))", "2(2(2+2(0))+2(2))", "2(2(2+2(0))+2(2)+2(0))", "2(2(2+2(0))+2(2)+2)"};

void power_two(int n, int pos = 14)
{
    for (int i = pos; i >= 0; i--)
    {
        if (n >= pow(2, i))
        {
            cout << str[i];
            n -= pow(2, i);
            if (n != 0)
            {
                cout << "+";
                power_two(n, i - 1);
            }
            break;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    power_two(n);
    return 0;
}