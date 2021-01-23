#include <iostream>
#include <string>
using namespace std;
int times[30];
string s;
int main()
{
    cin >> s;
    int maxt = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            int id = s[i] - 'a' + 1;
            times[id]++;
            maxt = max(maxt, times[id]);
        }
    }
    cout << maxt;
    return 0;
}