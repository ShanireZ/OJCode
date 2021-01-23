#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
string animals[100][100];
int features[100];

int same_feature(int a, int b)
{
    int count = 0;
    for (int i = 0; i < features[a]; i++)
    {
        for (int j = 0; j < features[b]; j++)
        {
            if (animals[a][i] == animals[b][j])
            {
                count++;
            }
        }
    }
    return count;
}

int main()
{
    int n;
    cin >> n;

    int type = 0;
    for (int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;
        cin >> features[i];
        for (int j = 0; j < features[i]; j++)
        {
            cin >> temp;
            animals[i][j] = temp;
        }
    }

    int max_yes = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            max_yes = max(max_yes, same_feature(i, j));
        }
    }

    cout << max_yes + 1;
    return 0;
}