#include <iostream>
using namespace std;
int main()
{
    int tot = 0;
    for (int i = 1; i <= 8; i++)
    {
        char tmp;
        cin >> tmp;
        if (tmp == '1')
        {
            tot++;
        }
    }
    cout << tot << endl;
    return 0;
}