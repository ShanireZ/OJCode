#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
struct Graph
{
    int state_1 = 0, state_2 = 0;
    char name;
};

int main()
{
    int n, q;
    cin >> n >> q;
    Graph group[n];
    for (int i = 0; i < n; i++)
    {
        cin >> group[i].name >> group[i].state_1;
        if (group[i].name == 'R')
        {
            cin >> group[i].state_2;
        }
    }

    for (int i = 0; i < q; i++)
    {
        int temp;
        cin >> temp;
        temp--;
        if (group[temp].name == 'T')
        {
            cout << "Triangle ";
        }
        else if (group[temp].name == 'R')
        {
            cout << "Rectangle ";
        }
        else
        {
            cout << "Circle ";
        }
        cout << group[temp].state_1 << " ";
        if (group[temp].name == 'R')
        {
            cout << group[temp].state_2;
        }
        cout << endl;
    }
    return 0;
}