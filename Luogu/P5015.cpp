#include <iostream>
using namespace std;
int main()
{
    char ch;
    int total = 0;
    while(cin >> ch)
    {
        if(ch != ' ' && ch != '\n')
        {
            total++;
        }
    }
    cout << total;
    return 0;
}