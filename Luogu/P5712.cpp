#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    cout << "Today, I ate " << n;
    if (n > 1)
    {
        cout << " apples.";
    }
    else
    {
        cout << " apple.";
    }
    return 0;
}