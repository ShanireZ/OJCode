#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n, r;
    cin >> n >> r;
    int origin = n;
    string str;
    while (n != 0)
    {
        int tmp = n % r;
        n = n / r;
        if (tmp < 0)
        {
            tmp = tmp - r;
            n++;
        }
        string ins;
        if (tmp < 10)
        {
            ins += (tmp + '0');
        }
        else
        {
            ins += (tmp - 10 + 'A');
        }
        str.insert(0, ins);
    }
    cout << origin << "=" << str << "(base" << r << ")";
    return 0;
}