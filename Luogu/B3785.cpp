#include <iostream>
using namespace std;
int main()
{
    int id;
    cin >> id;
    if (id == 1)
    {
        cout << "10 5 10";
    }
    else
    {
        cout << "100000\n";
        for (int i = 1; i <= 100000; i++)
        {
            cout << "std::cerr\n";
        }
    }
    return 0;
}