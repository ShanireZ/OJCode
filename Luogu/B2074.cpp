#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int a, b, ans = 1;
    cin >> a >> b;
    for (int i = 1; i <= b; i++)
    {
        ans = ans * a % 7;
    }
    if (ans == 0)
    {
        cout << "Sunday" << endl;
    }
    else if (ans == 1)
    {
        cout << "Monday" << endl;
    }
    else if (ans == 2)
    {
        cout << "Tuesday" << endl;
    }
    else if (ans == 3)
    {
        cout << "Wednesday" << endl;
    }
    else if (ans == 4)
    {
        cout << "Thursday" << endl;
    }
    else if (ans == 5)
    {
        cout << "Friday" << endl;
    }
    else if (ans == 6)
    {
        cout << "Saturday" << endl;
    }
    return 0;
}