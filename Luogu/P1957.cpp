#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <sstream>
using namespace std;
int main()
{
    int i, type;
    cin >> i;
    for (int j = 1; j <= i; j++)
    {
        string str;
        cin >> str;
        int n[5] = {0};
        if (str[0] >= 'a' && str[0] <= 'c')
        {
            type = str[0] - 'a';
            cin >> n[1] >> n[2];
        }
        else
        {
            stringstream ss;
            ss << str;
            ss >> n[1];
            cin >> n[2];
        }
        if (type == 0)
        {
            n[3] = n[1] + n[2];
            cout << n[1] << "+" << n[2] << "=" << n[3] << endl;
        }
        else if (type == 1)
        {
            n[3] = n[1] - n[2];
            cout << n[1] << "-" << n[2] << "=" << n[3] << endl;
        }
        else if (type == 2)
        {
            n[3] = n[1] * n[2];
            cout << n[1] << "*" << n[2] << "=" << n[3] << endl;
        }
        int tot = 2; //! 2个运算符
        for (int i = 1; i <= 3; i++)
        {
            if (n[i] == 0)
            {
                n[i]++;
            }
            if (n[3] < 0)
            {
                n[3] = -n[3];
                tot += 1; //! 负号也算1位
            }
            tot = tot + int(log10(n[i])) + 1;
        }
        cout << tot << endl;
    }
    return 0;
}