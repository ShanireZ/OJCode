#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
    int t[26] = {1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 4, 1, 2, 3, 1, 2, 3, 4};
    string str;
    getline(cin, str);
    int ans = 0;
    for(int i = 0; i < str.size(); i++)
    {
        if(str[i] == ' ')
        {
            ans += 1;
        }
        else if(str[i] >= 'a' && str[i] <= 'z')
        {
            ans += t[str[i] - 'a'];
        }
    }
    cout << ans;
    return 0;
}