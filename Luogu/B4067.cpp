#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string nums[5][5] = {{".....", ".***.", ".***.", ".***.", "....."},
                         {"****.", "****.", "****.", "****.", "****."},
                         {".....", "****.", ".....", ".****", "....."},
                         {".....", "****.", ".....", "****.", "....."}};
    string n;
    cin >> n;
    int a[10] = {0};
    for (int i = 0; i < (int)n.size(); i++)
    {
        a[i] = n[i] - '0';
    }
    for (int j = 0; j < 5; j++)
    {
        for (int i = 0; i < (int)n.size(); i++)
        {
            cout << nums[a[i]][j];
        }
        cout << endl;
    }
    return 0;
}